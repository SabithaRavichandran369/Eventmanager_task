#include<stdio.h>
#include<stdlib.h>

struct event_data
{
    int id;
    int event;
    void (*call_back)(int);
    struct event_data* next;
}*head=NULL,*temp,*tail;

void register_event(int module_id,int event,void (*call_back)(int))
{
    temp = (struct event_data*)malloc(sizeof(struct event_data*));
    temp->id=module_id;
    temp->event=event;
    temp->call_back=call_back;
    if(head==NULL)
    {
        head=tail=temp;
        return;
    }
    tail->next=temp;
    tail=temp;
    return;
}
int trigger_evt(int event)
{
    int ret=-1;
    temp=head;
    while(temp)
    {
        if(temp->event&(1<<event)){
        temp->call_back(event);
        ret=0;
        }
        temp=temp->next;
    }
    return ret;
}
void free_event()
{
	free(head);
	free(temp);
	free(tail);
}
