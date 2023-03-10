#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int i = 0;

pthread_mutex_t mutex;


void *thread_fun(void *arg){
	pthread_mutex_lock(&mutex);

	char* no = (char*)arg;
	for(;i < 5; i++){
		printf("%s thread, i:%d\n",no,i);
		// sleep(1);
	}
	i=0;

	pthread_mutex_unlock(&mutex);
}

int main(int argc, char const *argv[])
{
	pthread_t tid1, tid2;
	pthread_mutex_init(&mutex, NULL);

	pthread_create(&tid1, NULL, thread_fun, "tid1");
	pthread_create(&tid2, NULL, thread_fun, "tid2");

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	pthread_mutex_destroy(&mutex);
	return 0;
}
