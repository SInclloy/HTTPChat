#include "Thread.h"

void OpenChatThreads(struct ConnectionData* point)
{
	pthread_t threads[2];

	pthread_create(&threads[0], NULL, OpenConnection, (void*) point);
	pthread_create(&threads[1], NULL, Session, (void*)NULL);

	// pthread_create(&threads[0], NULL, OpenConnection(point),NULL);//OpenConnection(point)
	// pthread_create(&threads[1], NULL, Session(),NULL);//Session

	pthread_join(threads[0], NULL);
}