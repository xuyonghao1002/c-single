// **********************
// 一个客户端一个线程的模式
// **********************

#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>


#define MAX_READ_BUFFER 1024


void *func(void *arg){
	int client_fd = *(int*)arg;
	while(1){
		char buffer[MAX_READ_BUFFER] = {0};
		int ret = recv(client_fd, buffer, MAX_READ_BUFFER, 0);
		if(ret == 0){
			close(client_fd);
			break;
		}else if(ret < 0){
			// 这里表示读缓冲区为空，此时recv返回ret<0且有错误码
			if(errno == EAGAIN || errno == EWOULDBLOCK){
				continue;
			}
		}else{

		}
		printf("recv: %s", buffer);
		send(client_fd, buffer, ret, 0);
	}
}


int main(int argc, char const *argv[]){
	int listen_fd = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(struct sockaddr_in));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(9999);
	addr.sin_addr.s_addr = INADDR_ANY;

	if(bind(listen_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0){
		perror("bind");
		return -1;
	}

	if(listen(listen_fd, 10) < 0){
		perror("listen");
		return -1;
	}

	struct sockaddr_in client_addr;
	socklen_t len = sizeof(client_addr);


	while(1){
		int *client_fd = (int*)malloc(sizeof(int));
		*client_fd = accept(listen_fd, (struct sockaddr*)&client_addr, &len);
		pthread_t client_thread;
		pthread_create(&client_thread, NULL, func, client_fd);
	}


	return 0;
}
