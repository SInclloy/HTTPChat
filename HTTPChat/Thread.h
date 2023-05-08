//When we send HTTP messages we should close socket to avoid timer recv of Browser and send messages in moment
//
//
//
#pragma once

#include <pthread.h>

#include "OpenConnectionHTTP.h"
#include "APIView.h"

extern void OpenChatThreads(struct ConnectionData* point);