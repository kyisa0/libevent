#ifndef INTERNAL_H
#define INTERNAL_H
#include <stdbool.h>
#include <event.h>

struct event_loop_t{
	event_handle_t *handle_array[256];
	ar_info_t array_info[256];
	bool loop_stop_flag;
};



struct event_handle_t{
	loop_func lpfunc;
	int id;
	void *args;
};



typedef struct{
	bool avail;
}ar_info_t;
#endif
