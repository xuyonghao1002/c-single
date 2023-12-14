#include <stdio.h>
#include <event.h>
#include <sys/signal.h>

void signal_cb(int fd, short event, void* arg){

}

void timeout_cb(int fd, short event, void* arg){

}

int main(int argc, char const *argv[]) {
	struct event_base *evbase = event_base_new();

	struct event* signal_event = evsignal_new(evbase, SIGINT, signal_cb, evbase);
	event_add(signal_event, NULL);

	struct timeval tv = {1,0};
	struct event* timeout_event = evtimer_new(evbase, timeout_cb, NULL);
	event_add(timeout_event, &tv);

	event_base_dispatch(evbase);

	event_free(signal_event);
	event_free(timeout_event);
	event_base_free(evbase);

	return 0;
}