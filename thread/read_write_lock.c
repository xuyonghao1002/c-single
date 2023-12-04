
// 如何实现读写锁？
// 1. POSIX
// 2. 两把互斥锁
// 3. 互斥锁+条件变量

#include <pthread.h>
#include <stdio.h>

int count = 0;                          // 记录读线程个数
pthread_mutex_t mutex_count;            // 给count加锁
pthread_mutex_t mutex_data;             // 给数据加锁

#if 1
// 用两把互斥锁实现
void* read(void* arg){
	pthread_mutex_lock(&mutex_count);
	count++;							// 读线程个数加一，需要对count加锁
	if(count==1){						// count == 1，说明此时有一个读线程，则把数据加锁，不允许写操作，但不影响其他读操作
		pthread_mutex_lock(&mutex_data);
	}
	pthread_mutex_unlock(&mutex_count);
	// 读数据

	pthread_mutex_lock(&mutex_count);
	count--;
	if(count == 0){
		pthread_mutex_unlock(&mutex_data);
	}
	pthread_mutex_unlock(&mutex_count);
}

void* write(void* arg){
	pthread_mutex_lock(&mutex_data);
	// 写数据
	pthread_mutex_unlock(&mutex_data);
}
#endif

int main(int argc, char const *argv[])
{
	printf("12345\n");
	return 0;
}
