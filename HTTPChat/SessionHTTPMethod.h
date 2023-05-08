#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "PagesHTTP.h"
#include "SetString.h"
#include "TCP.h"

#define INVALID_CLIENT -1  

extern u_int ACCEPT_SOCKET;
extern char* ACCEPT_METHOD;
extern char* ACCEPT_REQUEST;

typedef struct Mail
{
	char* adresant;
	char* message;
}Mail;

typedef struct PostMail
{
	char* adresat;
	char* message;
}PostMail;

typedef struct Account
{
	char* username;
	char* time_to_out;

	PostMail postemail;
	Mail email;
} Account;

extern Account* InitClientAccount(char* request,
						   		  char* method,
						   		  int socket,
						   		  char* username,
						   		  char* time_to_out,
						   		  char* post_email_adresat,
						   		  char* post_email_message,
						   		  char* email_adresant,
						   		  char* email_message);
extern void InitSession(int clients,
						 char* username,
						 char* time_to_out,
						 char* post_email_adresat,
						 char* post_email_message,
						 char* email_adresant,
						 char* email_message);
extern int IsUserNameWritePOST();
extern int IsUserNameAdminPOST();
extern int IsUserNameOpponentWrite();
extern int IsHaveMessage();
extern void CreateNewMessagePOST(int id_from,int id_to);
extern int GetAcceptSessionAccount();
extern int GetSessionOpponent();
extern int GetEmptyPlaceInSession();
extern void ReleaseClientAccount();
extern void CreateNewUserInSession(int empty_id);
extern bool IsAcceptedClientHaveMessagePOST();
extern int GetSessionUserName(char* username);
extern char* GetMethodAcceptedClient();