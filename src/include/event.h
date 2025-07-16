#ifndef EVENT_H
#define EVENT_H


int event_init();
int run_loop();
int add_event();
int remove_event();
int event_stack_push(intptr_t value);
intptr_t event_stack_pop();
typedef struct event_loop_t event_loop_t;
typedef struct event_handle_t event_handle_t;

typedef void (*loop_func)(event_handle_t*, void*);

enum{
	MODE_NO_BLOCK, //No Blocking Mode loop will run independent from the main code
	MODE_RUN,      //Run Mode blocks until loop is ended
	MODE_IDLE      //Run Mode blocks until loop is completed (Needs a restart for the loop
};
#endif
