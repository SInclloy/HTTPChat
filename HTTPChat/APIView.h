//
//This thread responsibility is get client by Communication, send messages and close accepted client 
//
//
//
//
#pragma once

#include "СommunicationThreads.h"
#include "SessionHTTPMethod.h"

#define TOP_CLIENTS 10

#define GET 768
#define POST 978

extern void APIGet();
extern void APIView();
extern void* Session();