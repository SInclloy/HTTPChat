#include "СommunicationThreads.h"

struct SessionArgs
{
	char request[256];
	char method[256];
	char username[256];
	char username_opponent[256];
	char message[256];
	int socket;
} WaitedSessionClient = {.request = 0x00,
						 .method = 0x00,
						 .username = 0x00,
						 .username_opponent = 0x00,
						 .message = 0x00,
						 .socket = 0,};
int GetWaitedSessionClientSocket()
{
	return WaitedSessionClient.socket;
}
char* GetWaitedSessionClientMessage()
{
	return WaitedSessionClient.message;
}
char* GetWaitedSessionClientUsernameOpponent()
{
	return WaitedSessionClient.username_opponent;
}
char* GetWaitedSessionClientUsername()
{
	return WaitedSessionClient.username;
}
char* GetWaitedSessionClientMethod()
{
	return WaitedSessionClient.method;
}
char* GetWaitedSessionClientRequest()
{
	return WaitedSessionClient.request;
}
void SetWaitedSessionClientSocket(int socket)
{
	WaitedSessionClient.socket = socket;
}
void SetWaitedSessionClientMessage(char* message)
{
	strncpy(WaitedSessionClient.message,message,sizeof(WaitedSessionClient.message));
}
void SetWaitedSessionClientUsernameOpponent(char* username_opponent)
{
	strncpy(WaitedSessionClient.username_opponent,username_opponent,sizeof(WaitedSessionClient.username_opponent));
}
void SetWaitedSessionClientUsername(char* username)
{
	strncpy(WaitedSessionClient.username,username,sizeof(WaitedSessionClient.username));
}
void SetWaitedSessionClientMethod(char* method)
{
	strncpy(WaitedSessionClient.method,method,sizeof(WaitedSessionClient.method));
}
void SetWaitedSessionClientRequest(char* request)
{
	strncpy(WaitedSessionClient.request,request,sizeof(WaitedSessionClient.request));
}
void ReleaseWaitedSessionClient()
{
	char* null_string = NULL_STRING;

	strncpy(WaitedSessionClient.request,			null_string,	sizeof(WaitedSessionClient.request));
	strncpy(WaitedSessionClient.method,				null_string,	sizeof(WaitedSessionClient.method));
	strncpy(WaitedSessionClient.username,			null_string,	sizeof(WaitedSessionClient.username));
	strncpy(WaitedSessionClient.username_opponent,	null_string,	sizeof(WaitedSessionClient.username_opponent));
	strncpy(WaitedSessionClient.message,			null_string,	sizeof(WaitedSessionClient.message));
	WaitedSessionClient.socket = 0;
	
}