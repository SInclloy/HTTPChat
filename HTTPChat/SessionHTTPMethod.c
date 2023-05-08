#include "SessionHTTPMethod.h"

#define ADMIN "admin"
u_int CLIENTS = 0;

u_int ACCEPT_SOCKET = -1;
char* ACCEPT_METHOD = "\n";
char* ACCEPT_REQUEST = "\n";

char* NULL_USERNAME_SESSION = "\n";
char* NULL_TIME_TO_OUT_SESSION = "\n";
char* NULL_POST_EMAIL_ADRESAT_SESSION = "\n";
char* NULL_POST_EMAIL_MESSAGE_SESSION = "\n";
char* NULL_EMAIL_ADRESANT_SESSION = "\n";
char* NULL_EMAIL_MESSAGE_SESSION = "\n";

Account* session_clients;
Account* accepted_client;

char* GetMethodAcceptedClient()
{
	return ACCEPT_METHOD;
}
void SetUserNameSession(char* dst,int id_client_set)
{
	free(session_clients[id_client_set].username);
	session_clients[id_client_set].username = _strdup(session_clients[id_client_set].username,dst);
}
void SetPostEmailAdresantSession(char* dst,int id_client_set)
{
	free(session_clients[id_client_set].postemail.adresat);
	session_clients[id_client_set].postemail.adresat = _strdup(session_clients[id_client_set].postemail.adresat,dst);
}
void SetPostEmailMessageSession(char* dst,int id_client_set)
{
	free(session_clients[id_client_set].postemail.message);
	session_clients[id_client_set].postemail.message = _strdup(session_clients[id_client_set].postemail.message,dst);

}
void SetEmailAdresantSession(char* dst,int id_client_set)
{
	free(session_clients[id_client_set].email.adresant);
	session_clients[id_client_set].email.adresant = _strdup(session_clients[id_client_set].email.adresant,dst);
}
void SetEmailMessageSession(char* dst,int id_client_set)
{
	free(session_clients[id_client_set].email.message);
	session_clients[id_client_set].email.message = _strdup(session_clients[id_client_set].email.message,dst);
}
void ReleaseClientAccount()
{
	free(accepted_client);
}
Account* InitClientAccount(char* request,
						   char* method,
						   int socket,
						   char* username,
						   char* time_to_out,
						   char* post_email_adresat,
						   char* post_email_message,
						   char* email_adresant,
						   char* email_message)
{
	ACCEPT_SOCKET = socket;
	ACCEPT_METHOD = method;
	ACCEPT_REQUEST = request;

	accepted_client = (Account*)malloc(1*9 * sizeof(Account*));

	accepted_client->username = (char*)malloc(255 * sizeof(char));
	accepted_client->time_to_out = (char*)malloc(255 * sizeof(char));

	accepted_client->postemail.adresat = (char*)malloc(255 * sizeof(char));
	accepted_client->postemail.message = (char*)malloc(255 * sizeof(char));

	accepted_client->email.adresant = (char*)malloc(255 * sizeof(char));
	accepted_client->email.message = (char*)malloc(255 * sizeof(char));

	memcpy(accepted_client->username,				username,			255);
	memcpy(accepted_client->time_to_out,			time_to_out,		255);

	memcpy(accepted_client->postemail.adresat,		post_email_adresat,	255);
	memcpy(accepted_client->postemail.message,		post_email_message,	255);

	memcpy(accepted_client->email.adresant,			email_adresant,		255);
	memcpy(accepted_client->email.message,			email_message,		255);

}
int IsUserNameWritePOST()
{
	if(strlen(accepted_client->username) == 0)
	{
		_page_EnterYourName_http(ACCEPT_SOCKET);
		return 0;
	}
	return 1;
}
void AdminPOST()
{
	_pageSendHeaderAndStand_http(ACCEPT_SOCKET);
	for(int i = 0; i<=CLIENTS;i++)
	{
		_pageSendMessageAndStand_http("\n------------------USERNAME - ",		ACCEPT_SOCKET);
		_pageSendMessageAndStand_http(session_clients[i].username,				ACCEPT_SOCKET);
		_pageSendMessageAndStand_http("------------------\n",					ACCEPT_SOCKET);

		_pageSendMessageAndStand_http("\n              * post mail *",			ACCEPT_SOCKET);
		_pageSendMessageAndStand_http("\n	post adresat = ",					ACCEPT_SOCKET);
		_pageSendMessageAndStand_http(session_clients[i].postemail.adresat,		ACCEPT_SOCKET);
		_pageSendMessageAndStand_http("\n	post message = ",					ACCEPT_SOCKET);
		_pageSendMessageAndStand_http(session_clients[i].postemail.message,		ACCEPT_SOCKET);

		_pageSendMessageAndStand_http("\n                * email *",			ACCEPT_SOCKET);
		_pageSendMessageAndStand_http("\n	email.adresant = ",					ACCEPT_SOCKET);
		_pageSendMessageAndStand_http(session_clients[i].email.adresant,		ACCEPT_SOCKET);
		_pageSendMessageAndStand_http("\n	email.mail_message = ",				ACCEPT_SOCKET);
		_pageSendMessageAndStand_http(session_clients[i].email.message,			ACCEPT_SOCKET);
	}
	close_TCP(ACCEPT_SOCKET);
}
int IsUserNameAdminPOST()
{
	if(IsEqual(accepted_client->username,ADMIN))
	{
		printf("admin\n");
		AdminPOST();
		return 1;
	}
	return 0;
}
int IsUserNameOpponentWrite()
{
	if(strlen(accepted_client->postemail.adresat) != 0)
	{
		return 1;
	}
	return 0;
}
int IsHaveMessage()
{
	if(strlen(accepted_client->postemail.message) != 0)
		return 1;
	return 0;
}
void InitSession(int clients,
					 char* username,
					 char* time_to_out,
					 char* post_email_adresat,
					 char* post_email_message,
					 char* email_adresant,
					 char* email_message)
{
	CLIENTS = clients - 1;

	NULL_USERNAME_SESSION 				= username;
	NULL_TIME_TO_OUT_SESSION 			= time_to_out;
	NULL_POST_EMAIL_ADRESAT_SESSION 	= post_email_adresat;
	NULL_POST_EMAIL_MESSAGE_SESSION 	= post_email_message;
	NULL_EMAIL_ADRESANT_SESSION 		= email_adresant;
	NULL_EMAIL_MESSAGE_SESSION 			= email_message;

	session_clients = (Account*)malloc((clients)*10 * sizeof(Account*));

	for(int i =0;i<=CLIENTS;i++)
	{
		session_clients[i].username = (char*)malloc(255 * sizeof(char));
		session_clients[i].time_to_out = (char*)malloc(255 * sizeof(char));

		session_clients[i].postemail.adresat = (char*)malloc(255 * sizeof(char));
		session_clients[i].postemail.message = (char*)malloc(255 * sizeof(char));

		session_clients[i].email.adresant = (char*)malloc(255 * sizeof(char));
		session_clients[i].email.message = (char*)malloc(255 * sizeof(char));

		memcpy(session_clients[i].username,					username,			255);
		memcpy(session_clients[i].time_to_out,				time_to_out,		255);

		memcpy(session_clients[i].postemail.adresat,		post_email_adresat,	255);
		memcpy(session_clients[i].postemail.message,		post_email_message,	255);

		memcpy(session_clients[i].email.adresant,			email_adresant,		255);
		memcpy(session_clients[i].email.message,			email_message,		255);

	}
}
bool IsAccountHaveSomeMessages(int id_client)
{
	if(!IsEqual(session_clients[id_client].email.message,NULL_EMAIL_MESSAGE_SESSION))
	{
		return true;
	}
	return false;
}
bool IsAcceptedClientHaveMessagePOST()
{
	int my_id = GetAcceptSessionAccount();

	if(IsAccountHaveSomeMessages(my_id) == false)
	{
		return false;
	}
	if(IsAccountHaveSomeMessages(my_id) == true)
	{
		_pageSendHeaderAndStand_http(ACCEPT_SOCKET);

		_pageSendMessageAndStand_http(session_clients[my_id].email.adresant,ACCEPT_SOCKET);
		_pageSendMessageAndStand_http(":",ACCEPT_SOCKET);
		_pageSendMessageAndStand_http(session_clients[my_id].email.message,ACCEPT_SOCKET);

		close_TCP(ACCEPT_SOCKET);

		int id_account_adresant_email = GetSessionUserName(accepted_client->email.adresant);

		SetEmailAdresantSession(NULL_EMAIL_ADRESANT_SESSION,		my_id);
		SetEmailMessageSession(NULL_EMAIL_MESSAGE_SESSION,		my_id);
		SetPostEmailMessageSession(NULL_POST_EMAIL_MESSAGE_SESSION,		id_account_adresant_email);

		return true;
	}
}
void CreateNewMessagePOST(int id_from,int id_to)
{
	SetPostEmailMessageSession(accepted_client->postemail.message,id_from);

	SetEmailAdresantSession(accepted_client->username,	id_to);
	SetEmailMessageSession(accepted_client->postemail.message,	id_to);
	_pageYourMessageInSending(ACCEPT_SOCKET);

}
int GetSessionUserName(char* username)
{
	for(int i = 0;i <= 50;i++)
	{
		if(IsEqual(username,session_clients[i].username))
		{
			return i;
		}
		if(i == CLIENTS)
		{
			return INVALID_CLIENT;
		}
	}
}
int GetAcceptSessionAccount()
{
	for(int i = 0;i <= CLIENTS;i++)
	{
		if(IsEqual(session_clients[i].username,accepted_client->username))
		{
			return i;
		}
		if(i == CLIENTS)
		{
			return INVALID_CLIENT;
		}
	}
}
int GetSessionOpponent()
{
	for(int i = 0; i<= CLIENTS;i++)
	{
		if(IsEqual(accepted_client->postemail.adresat,session_clients[i].username))
		{
			return i;
		}

		if(i == CLIENTS)
		{
			return INVALID_CLIENT;
		}				
	}
}
int GetEmptyPlaceInSession()
{
	for(int i = 0;i <= CLIENTS;i++)
	{
		if(IsEqual(session_clients[i].username,NULL_USERNAME_SESSION))
		{
			return i;
		}
		if(i == CLIENTS)
		{
			return INVALID_CLIENT;
		}
	}
}
void CreateNewUserInSession(int empty_id)
{
	SetUserNameSession(accepted_client->username,	empty_id);
	SetPostEmailAdresantSession(accepted_client->username,	empty_id);
}