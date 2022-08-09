// main thread
    bool thread;

    uint8_t task1_cnts = 2, task2_cnts = 2;
    uint8_t task1_cntr = 0, task2_cntr = 0;
    bool task1_done, task1_state[task1_cnts];
    bool task2_done, task2_state[task2_cnts];


        if(task1_state[task1_cntr] == Yielding){
            
        }

    do{
        thread = true;

        ////////////////////////////////////////////////
        // task1
        do{
            task1_done = true;
            task1_state[task1_cntr] = function1();
            task1_state[task1_cntr] = function2();

            task1_done &= (task1_state[task1_cntr] == Done);
            task1_done &= (task1_state[task1_cntr] == Done);

        }while(!task1_done);

        ////////////////////////////////////////////////
        // task2
        do{
            task2_done = true;

            //if()
            task2_state[task2_cntr] = function5();
            task2_state[task2_cntr] = function6();

            task2_done &= (task2_state[task2_cntr] == Done);
            task2_done &= (task2_state[task2_cntr] == Done);

        }while(!task2_done);


        thread &= (task1_done == 1) && (task2_done == 1);
        printf("############################################\n");
        printf("thread %d\n",thread);


    }while(!thread);
	
	
// macros	
	
#define                                 \
    TaskStart                           \
    static int state = 0;               \
    switch(state)                       \
    {                                   \
        case 0:

#define 								\
    CheckBit(bit, bit_state)			\
        if(bit == bit_state)            \
        {                               \
            state = __LINE__;			\
            break;                      \
            case __LINE__:			    \
            ;           			    \
        }


#define                                 \
    TaskEnd                             \
    }                                   \
    state = 0	