#ifndef INTERNAL_H
#define INTERNAL_H
#include <stdbool.h>

typedef struct{
        bool avail;
}ar_info_t;

typedef struct event_loop_t event_loop_t;
typedef struct event_handle_t event_handle_t;

typedef void (*loop_func)(event_handle_t*, void*);

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


#endif
