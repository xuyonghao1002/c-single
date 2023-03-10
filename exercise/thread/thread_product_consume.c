#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define CONSUMER_NUM 2
#define PRODUCER_NUM 1

pthread_t pids[CONSUMER_NUM+PRODUCER_NUM];
int ready = 0;
pthread_mutex_t mutex;
pthread_cond_t has_product;


void* producer(void* arg){
	// 生成一个产品
	int id = (int)arg;
	while (1)
	{
		pthread_mutex_lock(&mutex);
		ready++;
		printf("producer %d success, current product num is %d\n", id, ready);
		pthread_cond_signal(&has_product);
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	
}

void* consumer(void* arg){
	// 消耗一个产品
	int id = (int)arg;
	while (1)
	{
		pthread_mutex_lock(&mutex);
		while(ready == 0){
			printf("consumer %d wait\n", id);
			pthread_cond_wait(&has_product, &mutex);
		}
		ready--;
		printf("consumer %d success, current product num is %d\n", id, ready);
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	
}


int main(){
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&has_product, NULL);

	int i;
	for (i = 0; i < CONSUMER_NUM; i++){
		pthread_create(&pids[i], NULL, consumer, (void*)i);
	}
	for (i = 0; i < PRODUCER_NUM; i++){
		pthread_create(&pids[CONSUMER_NUM+i], NULL, producer, (void*)i);
	}

	printf("thread create success!!\n");
	for(i=0; i<(CONSUMER_NUM+PRODUCER_NUM); i++){
		pthread_join(pids[i], NULL);
	}

	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&has_product);
	
	return 0;
}