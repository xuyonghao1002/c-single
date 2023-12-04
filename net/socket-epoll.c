// **********************
// epoll 的简单应用
// **********************


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <pthread.h>

#include <errno.h>
#include <fcntl.h>
#include <sys/epoll.h>

#define BUFFER_LENGTH 1024
#define POLL_SIZE 1024
#define EPOLL_SIZE 1024

int client_route(void *arg){
	int client_fd = *(int*)arg;

	while(1){
		char buffer[BUFFER_LENGTH] = {0};
		int ret = recv(client_fd, buffer, BUFFER_LENGTH, 0);
		if(ret < 0){
			if(errno == EAGAIN || errno == EWOULDBLOCK){
				printf("read all data\n");
			}
			// close(client_fd);
			return -1;
		} else if(ret == 0){
			printf("disconnect\n");
			return 0;
		} else{
			printf("recv: %s, %d bytes\n", buffer, ret);
			return ret;
		}
	}
}

int main(int argc, char const *argv[]){
	if(argc < 2){
		printf("paramter error\n");
		return -1;
	}

	int port = atoi(argv[1]);
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_fd < 0){
		perror("socket");
		return -1;
	}
#if 0
	int flag = fcntl(socket_fd, F_GETFL, 0);
	flag |= O_NONBLOCK;
	fcntl(socket_fd, F_SETFL, flag);
#endif
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(struct sockaddr_in));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = INADDR_ANY;

	if(bind(socket_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0){
		perror("bind");
		return 2;
	}

	if(listen(socket_fd, 5) < 0){
		perror("listen");
		return 3;
	}


	// epoll
	int epoll_fd = epoll_create(EPOLL_SIZE);
	struct epoll_event ev, events[EPOLL_SIZE] = {0};
	ev.events = EPOLLIN;
	ev.data.fd = socket_fd;
	epoll_ctl(epoll_fd, EPOLL_CTL_ADD, socket_fd, &ev);
	
	while(1){
		int nready = epoll_wait(epoll_fd, events, EPOLL_SIZE, -1);
		if(nready == -1){
			printf("epoll_wait\n");
			break;
		}
		for (int i = 0; i < nready; i++){
			if(events[i].data.fd == socket_fd){
				struct sockaddr_in client_addr;
				memset(&client_addr, 0, sizeof(struct sockaddr_in));
				socklen_t client_len = sizeof(client_addr);
				int client_fd = accept(socket_fd, (struct sockaddr*)&client_addr, &client_len);
				if(client_fd < 0) continue;

				// 将client fd添加到epoll管理
				ev.events = EPOLLIN | EPOLLET;
				ev.data.fd = client_fd;
				epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_fd, &ev);
				printf("add client fd into epoll");
			} else {
				int client_fd = events[i].data.fd;

				char buffer[BUFFER_LENGTH] = {0};
				int ret = recv(client_fd, buffer, BUFFER_LENGTH, 0);
				if(ret < 0){
					if(errno == EAGAIN || errno == EWOULDBLOCK){
						printf("read all data\n");
					}
					close(client_fd);
					ev.events = EPOLLIN | EPOLLET;
					ev.data.fd = client_fd;
					epoll_ctl(epoll_fd, EPOLL_CTL_DEL, client_fd, &ev);
				} else if(ret == 0){
					printf("disconnect\n");
					close(client_fd);
					ev.events = EPOLLIN | EPOLLET;
					ev.data.fd = client_fd;
					epoll_ctl(epoll_fd, EPOLL_CTL_DEL, client_fd, &ev);
					break;
				} else{
					printf("recv: %s, %d bytes\n", buffer, ret);
				}
			}
		}
	}

	


	return 0;
}
