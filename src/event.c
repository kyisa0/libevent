#include "internal.h"
#include <event.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//Initializies event library
void init_event()
{

}



//returns NULL if failed, returns pointer to loop structure if success
event_loop_t *new_loop()
{
	event_loop_t *p=(event_loop_t*)malloc(sizeof(event_loop_t));
	if(p==NULL)
	{
		return NULL;
	}
	for(int i=0;i<256;i++)
	{
		p->array_info[i].avail=true;
	}
	p->loop_stop_flag=false;
	return p;
}


//Returns NULL if error, returns pointer to handle if success
/*
--args--
loop: loop structure
func: function to be added to event loop
args: arguments passed to function
*/
event_handle_t *add_event(event_loop_t *loop, loop_func func, void *args)
{
	if(loop==NULL)
	{
		return NULL;
	}
	event_handle_t *handle=(event_handle_t*)malloc(sizeof(event_handle_t));
	if(handle==NULL)
	{
		return NULL;
	}
	handle->lpfunc=func;
	handle->args=args;
	for(int i=0;i<256;i++)
	{
		if(loop->array_info[i].avail==true)
		{
			handle->id=i;
			loop->handle_array[i]=handle; // problem here
			loop->array_info[i].avail=false;
			return handle;
		}
	}
	free(handle);
	return NULL;
}

void remove_event(event_loop_t *loop, event_handle_t *handle)
{
	if(loop==NULL)
	{
		return;
	}
	if(handle==NULL)
	{
		return;
	}
	loop->array_info[handle->id].avail=true;
	free(handle);
	return;

}

int run_loop(event_loop_t *loop, int loop_run_mode)
{
	while(!loop->loop_stop_flag)
	{
		for(int i=0;i<256;i++)
		{
			if(loop->array_info[i].avail==false){
				loop->handle_array[i]->lpfunc(loop->handle_array[i], loop->handle_array[i]->args);
			}
		}
	}
}
