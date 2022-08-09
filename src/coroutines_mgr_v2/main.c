/*	Title:	library manager
    Date:	Mon, 11 Jun 2021
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "coroutines_mgr_v2.h"
#include "../thread_task_mgr/thread_task_mgr.h"
#include "../modules/modules.h"
#include "../glcd/glcd.h"

void coroutine1()
{
    printf("\ncoroutine1 -------------------------------\n");
    static PfnCoroutine funcs[] = { function1, function2 };
    RunCoroutineParallel(2, funcs);
}

void coroutine2()
{
    printf("\ncoroutine2 -------------------------------\n");
    static PfnCoroutine funcs[] = { function3, function4 };
    RunCoroutineParallel(2, funcs);
}

////////////////////////////////////////////////////////////////////////////////////////////
// functions declarations

////////////////////////////////////////////////////////////////////////////////////////////
// global variables

////////////////////////////////////////////////////////////////////////////////////////////
// local continuation definitions
#define LC_INIT(s) s = 0;
#define LC_RESUME(s) switch(s) { case __LINE__:
#define LC_SET(s) s = __LINE__;
#define LC_END(s) s = 0; }

///////////////////////////////////////////////////////////
// coroutine function versions to work in the main function
///////////////////////////////////////////////////////////

// #1. coroutine version to work with bool locks
int cr_flag_state = 0;
bool coroutine_lock(void){
    static int i = 0;
    switch(cr_flag_state){
        case 0:
        do{
            if(i < 2000){
                cr_flag_state = __LINE__ + 3;
                printf("return 0; %d cr_flag_state %d\n",i, cr_flag_state);
                return 0;
                case __LINE__:
                    i++;
            }
        }while(i < 1000);
    }

    printf("return 1;\n");
    return 1;
}

// #2. coroutine version to work with timer delay counter checks
int cr_tmr_state = 0;
bool coroutine_timer(void){
    static int i;
    switch(cr_tmr_state){
        case 0:
        for(i = 0; i < 1000; i++){
            cr_tmr_state = __LINE__ + 3;
            printf("return 0; %d cr_tmr_state %d\n",i, cr_tmr_state);
            return 0;
            case __LINE__:
                ;
        }
    }

    printf("return 1;\n");
    return 1;
}

int main(){

////////////////////////////////////////////////////////////
// First version of coroutines implementation:
// * sequential coroutines control flow
// * tasks run in parallel for each coroutine
//    coroutine1();
//    coroutine2();

////////////////////////////////////////////////////////////
// Second version of coroutines implementation:
// * parallel coroutines control flow
// * tasks run in sequence for each coroutine

// main thread
    bool thread;

    uint8_t task1_cnts = 2, task2_cnts = 2;
    uint8_t task1_cntr = 0, task2_cntr = 0;
    bool task1_done, task1_state[task1_cnts];
    bool task2_done, task2_state[task2_cnts];

    bool SEN1_bit;

    task1_done = false;
    thread = false;

    start_time();

    do{
        do{

            TaskStart(task1_done);

            SEN1_bit = i2c_write();

            //CheckBit(SEN1_bit, true);
            if(SEN1_bit){printf("data 1 SEN1_bit = %d\n",SEN1_bit); break;}
            printf("data 1 sent\n");

            SEN1_bit = i2c_write();
            //CheckBit(SEN1_bit, true);
            if(SEN1_bit){printf("data 2 SEN1_bit  = %d\n",SEN1_bit); break;}
            printf("data 2 sent\n");

            TaskEnd;

            SEN1_bit = i2c_bit_set_clear_routine();

        }while(!task1_done);

        if(task1_done == 1){thread = true;}
        if(thread){printf("thread is done\n");}
    }while(!thread);



    return 0;
}
