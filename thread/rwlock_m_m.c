/*
	@file rwlock_m_m.c
	@author xuyonghao
	@date 2025-04-26
	@version 1.0
	@brief 使用2个互斥锁实现的读写锁
*/


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int count;
	pthread_mutex_t mutex_count;
	pthread_mutex_t mutex_data;
} rwlock_t;

void rwlock_init(rwlock_t *lock) {
	lock->count = 0;
	pthread_mutex_init(&lock->mutex_count, NULL);
	pthread_mutex_init(&lock->mutex_data, NULL);
}

void rwlock_rlock(rwlock_t *lock) {
	pthread_mutex_lock(&lock->mutex_count);
	if (lock->count == 0) {
		pthread_mutex_lock(&lock->mutex_data);
	}
	lock->count++;
	pthread_mutex_unlock(&lock->mutex_count);
}

void rwlock_runlock(rwlock_t *lock) {
	pthread_mutex_lock(&lock->mutex_count);
	lock->count--;
	if (lock->count == 0) {
		pthread_mutex_unlock(&lock->mutex_data);
	}
	pthread_mutex_unlock(&lock->mutex_count);
}

void rwlock_wlock(rwlock_t *lock) {
	pthread_mutex_lock(&lock->mutex_data);
}

void rwlock_wunlock(rwlock_t *lock) {
	pthread_mutex_unlock(&lock->mutex_data);
}

void rwlock_destroy(rwlock_t *lock) {
	pthread_mutex_destroy(&lock->mutex_count);
	pthread_mutex_destroy(&lock->mutex_data);
}