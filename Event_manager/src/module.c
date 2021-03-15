#include <stdio.h>
#include <event_manager.h>

void module1(int event)
{
    printf("in module1 with event : %d\n",event);
}

void module2(int event)
{
    printf("in module2 with event : %d\n",event);
}

void module3(int event)
{
    printf("in module3 with event : %d\n",event);
}

void module4(int event)
{
    printf("in module4 with event : %d\n",event);
}

void module5(int event)
{
     printf("in module5 with event : %d\n",event);
}

void (*fun_ptr[])(int)={&module1,&module2,&module3,&module4,&module5};

void input_event()
{
    int inputev;
    printf("enter event no : ");
    scanf("%d",&inputev);
    if(trigger_evt(inputev))
    printf("invalid event");
    
}

void module_init()
{
    char end;
    int module_id=1,n,event,temp,bit;
    for(;module_id<=5;module_id++){
        event=0;
        printf("enter the events for module %d : ",module_id);
        do
        {   
            scanf("%d",&temp);
            if(temp>=0&&temp<sizeof(int)*8)
            event |= (1<<temp);
            else{
            printf("skipping invalid event %d\n",temp);
            }
            
            scanf("%c",&end);
        }while(end!='\n');
        register_event(module_id,event,fun_ptr[module_id-1]);
    }
}

void module_deinit()
{
	free_event();
}
