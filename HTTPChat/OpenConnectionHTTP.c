#include "OpenConnectionHTTP.h"

void OpenClientSession(char* request,char* method,char* username,char* send_message_username,char* message,int socket,char* recv_data)
{
	if(GetWaitedSessionClientSocket() == 0)
	{

		SetWaitedSessionClientRequest(request);
		SetWaitedSessionClientMethod(method);
		SetWaitedSessionClientUsername(username);
		SetWaitedSessionClientUsernameOpponent(send_message_username);
		SetWaitedSessionClientMessage(message);
		SetWaitedSessionClientSocket(socket);

		printf("%s\n",recv_data);
		printf(KGRN"%s\n\n"RESET,GetWaitedSessionClientRequest());
		
	}
}
void RegistrationClient(int client_socket)
{
	while (1)
	{
		char recv_data[BUFSIZ] = {0};
		char request[BUFSIZ] = {0};
		char method[BUFSIZ]= {0};
		char username[BUFSIZ] = {0};
		char send_message_username[BUFSIZ] = {0};
		char message[BUFSIZ] = {0};

		int RecvResult = recv(client_socket, recv_data, BUFSIZ, 0);

		if(RecvResult > 0)
	 	{
			GetRequest(request,recv_data);
			GetMethodRequest(request,method);
			GetStringFromRequest(request,username,2);
			GetStringFromRequest(request,send_message_username,3);
			GetStringFromRequest(request,message,4);
			
			OpenClientSession(request,
							  method,
							  username,
							  send_message_username,
							  message,
							  client_socket,
							  recv_data);
			break;
		}
	}
}
void NewClientConnection(struct ConnectionData* point)
{
	AcceptSocketTCP(point);
	RegistrationClient(point->Socket_II);
}
void* OpenConnection(struct ConnectionData* point)
{
	printf("Listenning the port ...\n");

	while(1)
	{
		NewClientConnection(point);
	}
	return NULL;
}