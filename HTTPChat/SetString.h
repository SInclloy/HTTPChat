#pragma once
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\033[0m"

#define NULL_STRING "\n"

typedef unsigned long u_long;
typedef unsigned int u_int;

static inline char* _strdup(char* str1,char* str2)
{
	str1 = (char*)malloc(255 * sizeof(str2));
	memcpy(str1,str2,strlen(str2));
	return str1;

}
static inline u_int HashFunc(char* method)   		
{
	u_int Hash = 0;

	for(int i = 0; i<sizeof(method);i++)
	{
		if(method[i] != '\n')
		{
			Hash += method[i] * 3;
		}
	}
	return Hash;
}
static inline bool IsEqual(char* ferst_string, char* second_string)
{
	int IsEqual = strcmp(ferst_string,second_string);
	if(IsEqual != 0)
		return false;
	return true;
}
static inline void GetRequest(char request[],char buffer[])
{
	for(int i=0;i<BUFSIZ;i++)
	{
		if(buffer[i]=='\n')
		{
			strncpy(request,buffer,i);
			request[i] = '\0';
			break;		
		}
	}
}
static inline void GetMethodRequest(char full_request[],char method[] )
{
	size_t request_size = strlen(full_request);

	for(int i=0;i<request_size;i++)
	{
		if(full_request[i]=='/')
		{
			strncpy(method,full_request,i);
			method[i] = '\0';
			break;		
		}
	}
}
static inline void GetUserNameRequest(char full_request[],char UserName[] )      //problem
{
	size_t request_size = strlen(full_request);

	char adapter[255] = {0};
	int SlashCounter = 0;
	int SlashPoseLast = 0;

	for(int i=0;i<request_size;i++)
	{
		if(full_request[i]=='/')
		{
			SlashCounter++;
			

			if(SlashCounter == 2)
			{
				strncpy(adapter,full_request,i);
				adapter[i] = '\0';
				strncpy(UserName,adapter + SlashPoseLast+1,sizeof(adapter));
				break;
			}
			SlashPoseLast = i;
			
		}
	}
}
static inline void GetSendMessageUserName(char full_request[],char username[])
{
	size_t request_size = strlen(full_request);

	char adapter[255] = {0};
	int SlashCounter = 0;
	int SlashPoseLast = 0;

	for(int i=0;i<request_size;i++)
	{
		if(full_request[i]=='/')
		{
			SlashCounter++;
			

			if(SlashCounter == 3)
			{
				strncpy(adapter,full_request,i);
				adapter[i] = '\0';
				strncpy(username,adapter + SlashPoseLast+1,sizeof(adapter));
				return;
			}
			SlashPoseLast = i;
			
		}
	}
}

static inline void GetStringFromRequest(char full_request[],char buffer_string[],int count_slash)
{
	size_t size = strlen(full_request);
	int isize = (int)size; //HTTP/1.1
	int size_wihout_http_version = size - 10;

	char adapter[255] = {0};
	int SlashCounter = 0;
	int SlashPoseLast = 0;

	for(int i=0;i<size_wihout_http_version;i++)
	{
		if(full_request[i]=='/')
		{
			SlashCounter++;
			

			if(SlashCounter == count_slash)
			{
				strncpy(adapter,full_request,i);
				adapter[i] = '\0';
				strncpy(buffer_string,adapter + SlashPoseLast+1,sizeof(adapter));
				break;
			}
			SlashPoseLast = i;
			
		}
	}
}

static inline void GetMessageRequest(char full_request[],char message[])
{
	size_t request_size = strlen(full_request);

	char adapter[255] = {0};
	int SlashCounter = 0;
	int SlashPoseLast = 0;

	for(int i=0;i<request_size;i++)
	{
		if(full_request[i]=='/')
		{
			SlashCounter++;
			

			if(SlashCounter == 4)
			{
				strncpy(adapter,full_request,i);
				adapter[i] = '\0';
				strncpy(message,adapter + SlashPoseLast+1,sizeof(adapter));
				return;
			}
			SlashPoseLast = i;
			
		}
	}
}