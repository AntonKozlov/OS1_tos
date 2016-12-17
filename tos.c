
#include "tos.h"

void tos_init(void) {

}

void tos_sleep(int msec) {

}

int tos_gettime(void) {
	return 0;
}

int tos_add_thread(void (*start_fn)(void *), void *param) {
	start_fn(param);
	return 0;
}

int tos_start(void) {
	return 0;
}

