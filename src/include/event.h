#ifndef EVENT_H
#define EVENT_H

typedef struct event_loop_t event_loop_t;
typedef struct event_handle_t event_handle_t;

typedef void (*loop_func)(event_handle_t*, void*);


void init_event();
event_loop_t *new_loop();
event_handle_t *add_event(event_loop_t *loop, loop_func func, void *args);
void remove_event(event_loop_t *loop, event_handle_t *handle);
int run_loop(event_loop_t *loop, int loop_run_mode);


enum{
	MODE_NO_BLOCK, //No Blocking Mode loop will run independent from the main code
	MODE_RUN,      //Run Mode blocks until loop is ended
	MODE_IDLE      //Run Mode blocks until loop is completed (Needs a restart for the loop
};
#endif
