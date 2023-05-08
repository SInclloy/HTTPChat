
// version 9000
#include "Thread.h"

int main(int argc, char **argv)
{
	struct ConnectionData data;
	data.Socket_II = 0;
	data.Socket_Jr =0;
	data.port = 1738;

	for(int x = 0;x<50;x++)
		printf("\n");

	Init_TCP_Socket(&data);
	OpenChatThreads(&data);
	
	return 0;

}