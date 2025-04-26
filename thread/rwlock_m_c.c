/*
	@file rwlock_m_m.c
	@author xuyonghao
	@date 2025-04-26
	@version 1.0
	@brief 使用互斥锁和条件变量实现的读写锁
*/


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	pthread_mutex_t mutex;  // 互斥锁
	pthread_cond_t readers_ok;
	pthread_cond_t writers_ok;
	int readers;
	int writers;
	int waiting_writers;
} rwlock_t;

// 初始化读写锁
void rwlock_init(rwlock_t *lock) {
	pthread_mutex_init(&lock->mutex, NULL);
	pthread_cond_init(&lock->readers_ok, NULL);
	pthread_cond_init(&lock->writers_ok, NULL);
	lock->readers = 0;
	lock->writers = 0;
	lock->waiting_writers = 0;
}

// 申请读锁
void rwlock_rlock(rwlock_t *lock) {
	pthread_mutex_lock(&lock->mutex);
	// 写优先，如果有写线程等待，则不允许继续加读锁
	while (lock->writers > 0 || lock->waiting_writers > 0) {
		pthread_cond_wait(&lock->readers_ok, &lock->mutex);
	}
	lock->readers++;
	pthread_mutex_unlock(&lock->mutex);
}

// 释放读锁
void rwlock_runlock(rwlock_t *lock) {
	pthread_mutex_lock(&lock->mutex);
	lock->readers--;
	// 如果有写线程等待，则唤醒一个写线程
	if (lock->readers == 0 && lock->waiting_writers > 0) {
		pthread_cond_signal(&lock->writers_ok);
	}
	pthread_mutex_unlock(&lock->mutex);
}

// 申请写锁
void rwlock_wlock(rwlock_t *lock) {
	pthread_mutex_lock(&lock->mutex);
	while (lock->writers > 0 || lock->readers > 0) {
		lock->waiting_writers++;
		pthread_cond_wait(&lock->writers_ok, &lock->mutex);
		lock->waiting_writers--;
	}
	lock->writers = 1;
	pthread_mutex_unlock(&lock->mutex);
}

// 释放写锁
void rwlock_wunlock(rwlock_t *lock) {
	pthread_mutex_lock(&lock->mutex);
	lock->writers = 0;
	// 如果有等待的写线程，则唤醒一个
	if (lock->waiting_writers > 0) {
		pthread_cond_signal(&lock->writers_ok);
	} else {
		// 唤醒所有读线程
		pthread_cond_broadcast(&lock->readers_ok);
	}
	pthread_mutex_unlock(&lock->mutex);
}

// 销毁读写锁
void rwlock_destroy(rwlock_t *lock) {
	pthread_mutex_destroy(&lock->mutex);
	pthread_cond_destroy(&lock->readers_ok);
	pthread_cond_destroy(&lock->writers_ok);
}


