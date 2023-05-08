// In this makes communication between Session and Opened Connection
//
//
#pragma once

#include "SetString.h"

struct SessionArgs;

int GetWaitedSessionClientSocket();
char* GetWaitedSessionClientMessage();
char* GetWaitedSessionClientUsernameOpponent();
char* GetWaitedSessionClientUsername();
char* GetWaitedSessionClientMethod();
char* GetWaitedSessionClientRequest();
void SetWaitedSessionClientSocket(int socket);
void SetWaitedSessionClientMessage(char* message);
void SetWaitedSessionClientUsernameOpponent(char* username_opponent);
void SetWaitedSessionClientUsername(char* username);
void SetWaitedSessionClientMethod(char* method);
void SetWaitedSessionClientRequest(char* request);
void ReleaseWaitedSessionClient();