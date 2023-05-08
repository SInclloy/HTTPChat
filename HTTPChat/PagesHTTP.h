#pragma once

#include <stdlib.h>
#include "TCP.h"
#include "SetString.h"

static inline void _pageSendMessageAndStand_http(char* buffer,int conn)
{
	char* send_message = (char*)malloc(255 * 500);

	strcpy(send_message,buffer);
	size_t headsize = strlen(send_message);
	send_TCP(conn, send_message, headsize);
	free(send_message);
}
static inline void _page404_http(int conn) 
{
	char *header = "HTTP/1.1 404 Not Found\n\nnot found";
	size_t headsize = strlen(header);
	send_TCP(conn, header, headsize);
	close_TCP(conn);
}
static inline void _pageYouAreIntheSession_http(int conn) 
{
	char *header = "HTTP/1.1 200 InSession\n\nYou are in the session";
	size_t headsize = strlen(header);
	send_TCP(conn, header, headsize);
	close_TCP(conn);
}
static inline void _pageSendHeaderAndStand_http(int conn) 
{
	char *header = "HTTP/1.1 200 Success\n\n";
	size_t headsize = strlen(header);
	send_TCP(conn, header, headsize);
}
static inline void _pageUserInSession_http(int conn) 
{
	char *header = "HTTP/1.1 200 InSession\n\nUser in session";
	size_t headsize = strlen(header);
	send_TCP(conn, header, headsize);
	close_TCP(conn);
}
static inline void _pageUserOutOfSession_http(int conn) 
{
	char *header = "HTTP/1.1 200 OutOfSession\n\nUser out of session";
	size_t headsize = strlen(header);
	send_TCP(conn, header, headsize);
	close_TCP(conn);
}
static inline void _pageFaultUsername_http(int conn) 
{
	char *header = "HTTP/1.1 404 Not Found\n\nEnter your username";
	size_t headsize = strlen(header);
	send_TCP(conn, header, headsize);
	close_TCP(conn);
}
static inline void _pageSessionIsFullOfClients_http(int conn) 
{
	char *header = "HTTP/1.1 404 SessionIsFullOfClients\n\nSession is full of clients";
	size_t headsize = strlen(header);
	send_TCP(conn, header, headsize);
	close_TCP(conn);
}
static inline void _pageTryLater_http(int conn) 
{
	char *header = "HTTP/1.1 200 Try later\n\nTry later";
	size_t headsize = strlen(header);
	send_TCP(conn, header, headsize);
}
static inline void _page_EnterYourName_http(int conn) 
{
	char *header = "HTTP/1.1 200 Success\n\nEnter your name!";//"HTTP/1.1 404 Not Found\n\nnot found";
	size_t headsize = strlen(header);
	send_TCP(conn, header, headsize);
	close_TCP(conn);
}
static inline void _pageSendMessageInWorking_http(int conn) 
{
	char *header = "HTTP/1.1 200 SendMessageInWorking\n\nSend Message In Working";
	size_t headsize = strlen(header);
	send_TCP(conn, header, headsize);
}
static inline void _pageNoApponentInSession_http(int conn) 
{
	char *header = "HTTP/1.1 400 NoApponentInSession\n\nNo apponent in session or failer username";
	size_t headsize = strlen(header);
	send_TCP(conn, header, headsize);
}
static inline void _pageApponentInSession_http(int conn) 
{
	char *header = "HTTP/1.1 200 ApponentInSession\n\nApponent in session";
	size_t headsize = strlen(header);
	send_TCP(conn, header, headsize);
}
static inline void _pageNoNewMessages_http(int conn) 
{
	char *header = "HTTP/1.1 200 NoNewMessages\n\nNo messages";
	size_t headsize = strlen(header);
	send_TCP(conn, header, headsize);
}
static inline void _pageYourMessageInSending(int conn)
{
	char *header = "HTTP/1.1 200 In sending\n\nYour message in sending";
	size_t headsize = strlen(header);
	send_TCP(conn, header, headsize);
	close_TCP(conn);
}