#include <stdio.h>

#include "tos.h"

#define USUAL_BUSY_SLEEP_TIME 1000000

void busy_sleep(int count) {
	volatile int cnt = count;
	while (--cnt) { }
}

void tick(const char *thread_name, int thread_state) {
	printf("%s: tick state=%d time=%d\n", thread_name, thread_state, tos_gettime());
}

void thread_busy_sleep(void *param) {
	while (1) {
		tick(__func__, 1);
		busy_sleep(USUAL_BUSY_SLEEP_TIME);
	}
}

void thread_tosy_sleep(void *param) {
	while (1) {
		tick(__func__, 1);
		tos_sleep(1000);

		tick(__func__, 2);
		busy_sleep(USUAL_BUSY_SLEEP_TIME);
	}
}

int main(int argc, char *argv[]) {
	tos_init();

	if (tos_add_thread(thread_tosy_sleep, NULL)) {
		return 1;
	}

	if (tos_add_thread(thread_busy_sleep, NULL)) {
		return 2;
	}

	return tos_start();
}
