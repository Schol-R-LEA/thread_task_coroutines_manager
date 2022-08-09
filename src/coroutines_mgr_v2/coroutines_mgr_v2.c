#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>
#include "coroutines_mgr_v2.h"
#include "../modules/modules.h"
////////////////////////////////////////////////////////////////////////////////////////////
// global variables

////////////////////////////////////////////////////////////////////////////////////////////
// functions definitions
unsigned long millis(void){
    unsigned long t_val;
    t_val = GetTickCount();
    return t_val;
}

void RunCoroutineParallel(uint8_t count_, PfnCoroutine funcs[])
{
    bool done;
    uint8_t i;

    bool *state = (bool *) malloc(sizeof(bool) * count_);
    for(i = 0; i< count_; i++){state[i] = Yielding;}

    do
    {
        // loop starting lock, which will be initialized to true
        // each loop
        done = true;
        for (i = 0; i < count_; i++)
        {
            if (state[i] == Yielding){  // if task isn't finished
                state[i] = funcs[i]();  // run the task
            }

            // any task that isn't finished yet, will change
            // the original value of done which is "true"

            /// for example
            // if the result of any AND operation
            // whether it's at the start index or last
            // the actual value of done will be false
            // so any true result of state[i] == Done will not
            // change the value of done, so the loop has to start
            // again, with initializing done = true
            // so all AND operations MUST be true
            // --> done = ``done`` & (state[i] == Done);
            done &= state[i] == Done;
        }
    } while (!done);

    free(state);
}

void RunCoroutineSequential(uint8_t count_, PfnCoroutine funcs[])
{
    bool done;
    uint8_t i;

    bool *state = (bool *) malloc(sizeof(bool) * count_);
    for(i = 0; i< count_; i++){state[i] = Yielding;}

    do
    {
        // loop starting lock, which will be initialized to true
        // each loop
        done = true;
        for (i = 0; i < count_; i++)
        {
            if (state[i] == Yielding){  // if task isn't finished
                state[i] = funcs[i]();  // run the task
            }

            // any task that isn't finished yet, will change
            // the original value of done which is "true"
            done &= state[i] == Done;
        }
    } while (!done);

    free(state);
}

