#ifndef EVENT_H
#define EVENT_H


int event_init();
int run_loop();
int add_event();
int remove_event();
int event_stack_push(intptr_t value);
intptr_t event_stack_pop();

#endif
