//
//This thread responsibility is accept socket and registration him in CommunicationThreads.h
//
//
//
#pragma once

#include <unistd.h>

#include "SetString.h"
#include "TCP.h"
#include "PagesHTTP.h"
#include "СommunicationThreads.h"


#define MAX_CLIENTS 4   //todo: delete

typedef struct connection_info
{
  int socket;
} connection_info;


extern void OpenClientSession(char* request,char* method,char* username,char* send_message_username,char* message,int socket,char* recv_data);
extern void RegistrationClient(int client_socket);
extern void NewClientConnection(struct ConnectionData* point);
extern void* OpenConnection(struct ConnectionData* point);