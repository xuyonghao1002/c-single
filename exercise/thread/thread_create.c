#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* xc(void *arg){
	char *c = (char*)arg;
	printf("参数：%s\n", c);
	for (int i = 0; i < 5; i++)
	{
		printf("循环：%d\n", i);
		if(i == 5){
			char* result = "12345";
			pthread_exit(result);
		}
	}
}


int main(int argc, char const *argv[])
{
	pthread_t tid;
	pthread_create(&tid, NULL, xc, "thread test");

	void* status;
	pthread_join(tid, &status);
	printf("返回：%s\n", (char*)status);



	return 0;
}
