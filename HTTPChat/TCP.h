#pragma once

#include <sys/select.h>
#include <errno.h>
#include <arpa/inet.h>
#include <stdint.h>
#include <unistd.h>

#include "SetString.h"

#define NONBLOCK (u_long)1
#define INVALID_SOCKET  (int)(~0)

// typedef struct ConnectionData
// {
// 	struct sockaddr_in SocketAddr;

// 	int Socket_Jr;
// 	int Socket_II;

// } ConnectionData;

// typedef struct ConnectionPoint
// {
// 	int* port;

// 	struct ConnectionData* info;
// } ConnectionPoint;



typedef struct ConnectionData
{
	int Socket_Jr;
	int Socket_II;

	int port;
}ConnectionData;

int close_TCP(int conn);
int send_TCP(int conn, char* buffer, size_t size);
void Init_TCP_Socket(struct ConnectionData* point);
int AcceptSocketTCP(struct ConnectionData* sData);