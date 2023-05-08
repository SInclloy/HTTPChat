#include "APIView.h"

void APIGet()
{
	if(IsUserNameWritePOST() == false)
	{
		printf(KRED"user is not write\n"RESET);
		return;
	}
	if(IsUserNameAdminPOST())
	{
		printf(KRED"user is admin\n"RESET);
		return;
	}
	
	int id_client = GetAcceptSessionAccount();

	if(id_client != INVALID_CLIENT)
	{
		printf("User already in session\n");

		if(IsUserNameOpponentWrite())
		{
			printf("User have opponent\n");

			if(IsHaveMessage())
			{
				printf("User have some message\n");

				int id_opponent = GetSessionOpponent();
				int my_id = GetAcceptSessionAccount();

				if(id_opponent != INVALID_CLIENT)
				{
					printf("Send message\n");

					CreateNewMessagePOST(my_id,id_opponent);
					return;
				}
				if(id_opponent == INVALID_CLIENT)
				{
					printf("No opponent of user in session\n");

					_pageUserOutOfSession_http(ACCEPT_SOCKET);
					return;
				}
			}
			if(IsHaveMessage() == false)
			{
				printf("User do not have some message\n");

				int id_opponent = GetSessionOpponent();

				if(id_opponent != INVALID_CLIENT)
				{
					printf("Opponent of user in session\n");

					_pageUserInSession_http(ACCEPT_SOCKET);
					return;
				}
				if(id_opponent == INVALID_CLIENT)
				{
					 printf("No opponent of user in session\n");

					_pageUserOutOfSession_http(ACCEPT_SOCKET);
					return;
				}
			}
		}
		if(IsUserNameOpponentWrite() == false)
		{
			printf("User do not have opponent\n");

			if(IsAcceptedClientHaveMessagePOST() == true)
			{
				printf("Get user message\n");
				return;
			}
			if(IsAcceptedClientHaveMessagePOST() == false)
			{
				printf("No user message get\n");

				_pageYouAreIntheSession_http(ACCEPT_SOCKET);
				return;
			}

		}
	}
	if(id_client == INVALID_CLIENT)
	{
		printf("No this user in session\n");

		int id_empty_place = GetEmptyPlaceInSession();

		if(id_empty_place != INVALID_CLIENT)
		{
			printf("Add user to session\n");

			CreateNewUserInSession(id_empty_place);

			if(IsUserNameOpponentWrite())
			{
				printf("User have opponent\n");

				if(IsHaveMessage())
				{
					printf("User have some message\n");

					int id_opponent = GetSessionOpponent();
					int my_id = GetAcceptSessionAccount();

					if(id_opponent != INVALID_CLIENT)
					{
						printf("Send message\n");
						CreateNewMessagePOST(my_id,id_opponent);
						return;
					}
					if(id_opponent == INVALID_CLIENT)
					{
						printf("No opponent of user in session\n");

						_pageUserOutOfSession_http(ACCEPT_SOCKET);
						return;
					}
				}
				if(IsHaveMessage() == false)
				{
					printf("User do not have some message\n");

					int id_opponent = GetSessionOpponent();

					if(id_opponent != INVALID_CLIENT)
					{
						printf("Opponent of user in session\n");

						_pageUserInSession_http(ACCEPT_SOCKET);
						return;
					}
					if(id_opponent == INVALID_CLIENT)
					{
						printf("No opponent of user in session\n");

						_pageUserOutOfSession_http(ACCEPT_SOCKET);
						return;
					}
				}
			}
			if(IsUserNameOpponentWrite() == false)
			{
				printf("User do not have opponent\n");

				_pageYouAreIntheSession_http(ACCEPT_SOCKET);
				return;
			}
		}
		if(id_empty_place == INVALID_CLIENT)
		{
			printf(KRED"Session is filled\n"RESET);
			return;
		}
	}

}
void APIView()
{
	u_int hash = HashFunc(GetMethodAcceptedClient());

	switch (hash)
	{
	case GET:
		APIGet();
		return;
	
	case POST:
		printf("in develop\n");
		return;
	//delete,put...
	}
}

void* Session()
{
	int clients					= TOP_CLIENTS;

	char* username				= "nullclient";
	char* time_to_out			= "0.0.0.0\n";

	char* post_email_adresat	= "nullclient";
	char* post_email_message	= "\n";

	char* email_adresant		= "\n";
	char* email_message			= "nomessages\n";

	InitSession(clients,username,time_to_out,post_email_adresat,post_email_message,email_adresant,email_message);

	while(true)
	{
		if(GetWaitedSessionClientSocket() != 0)
		{
			char* request 		= GetWaitedSessionClientRequest();
			char* method 		= GetWaitedSessionClientMethod();
			int socket 			= GetWaitedSessionClientSocket(); 

			username 			= GetWaitedSessionClientUsername();
			time_to_out			= "0.0.0.0\n";

			post_email_adresat 	= GetWaitedSessionClientUsernameOpponent();
			post_email_message 	= GetWaitedSessionClientMessage();
			
			email_adresant 		= "\n";
			email_message 		= "nomessages\n";

			InitClientAccount(request,method,socket,username,time_to_out,post_email_adresat,post_email_message,email_adresant,email_message);
			APIView();

			ReleaseWaitedSessionClient();
			ReleaseClientAccount();

		}
		//todo: time to out
	}
	return NULL;
}