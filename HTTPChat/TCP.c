#include "TCP.h"

void ERROR_IOCTLSOCKET()
{
	printf("ERROR_IOCTLSOCKET %s\n",strerror(errno));
}
void ERROR_SETSOCKOPT()
{

	printf("ERROR_SETSOCKOPT %s\n",strerror(errno));

}
void ERROR_BIND()
{
	printf("ERROR_BIND %s\n",strerror(errno));
}
void ERROR_LISTEN()
{
	printf("ERROR_LISTEN %s\n",strerror(errno));
}

int close_TCP(int conn)
{
	return close(conn);
}
int send_TCP(int conn, char* buffer, size_t size)
{
	return send(conn, buffer,(int)size,0);
}
void Init_TCP_Socket(struct ConnectionData* point)
{
	struct sockaddr_in SocketAddr;
	u_long nonblock_socket = NONBLOCK;
	int OptValMode = 1; 
	int backlog = SOMAXCONN;
	uint16_t port = (uint16_t)point->port;

	point->Socket_Jr = socket(AF_INET, SOCK_STREAM, 0);
	SocketAddr.sin_family = AF_INET;
	SocketAddr.sin_addr.s_addr = INADDR_ANY;
	SocketAddr.sin_port = htons(port);

	if (setsockopt(point->Socket_Jr, SOL_SOCKET, SO_REUSEADDR, (char *)&OptValMode, sizeof(int))
		== INVALID_SOCKET)
		ERROR_SETSOCKOPT();

	if (bind(point->Socket_Jr, (struct sockaddr*)&SocketAddr, sizeof(SocketAddr))
		== INVALID_SOCKET)
		ERROR_BIND();

	if (listen(point->Socket_Jr, backlog)
		== INVALID_SOCKET)
		ERROR_LISTEN();

}
int AcceptSocketTCP(struct ConnectionData* sData)
{
	sData->Socket_II = accept(sData->Socket_Jr, NULL, NULL);
	
	if (sData->Socket_II < 0)
	{
		printf("accept invalid\n");
		return -10;
	}
	return 1;
}