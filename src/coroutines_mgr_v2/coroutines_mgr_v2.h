#ifndef COROUTINES_MGR_V2_H_INCLUDED
#define COROUTINES_MGR_V2_H_INCLUDED
////////////////////////////////////////////////////////////////////////////////////////////
// libraries

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>

//////////////////////////////////////////////////////////////////////////////////
// definitions
#define                                                 \
    BeginCoroutine                                      \
    static int state = 0;                               \
    switch(state)                                       \
    {                                                   \
        case 0:

#define 								                \
    CoroutineDelay(prd)									\
    do												    \
    {												    \
        static unsigned long st_millis = 0;			    \
        for(st_millis = millis();                       \
            millis() - st_millis < prd; )               \
        {                                               \
            state = __LINE__;			                \
            return Yielding;                            \
            case __LINE__:			                    \
            ;                                           \
        }			                                    \
        printf("t_elapsed %lu prd done\t%d\tline done %d\
        \n\n", millis() - st_millis , prd, __LINE__);   \
    }			                                        \
    while(0)

#define                                                 \
    EndCoroutine                                        \
    }                                                   \
    state = 0; 					            			\
    printf("FUNC DONE# %s\n", __func__);                \
    return Done

//////////////////////////////////////////////////////////////////////////////////
// enumerations
typedef enum { Yielding, Done } crState;
// function pointer
typedef bool (*PfnCoroutine)();
// pointers

// variables

//////////////////////////////////////////////////////////////////////////////////
// functions
unsigned long millis(void);
void RunCoroutineParallel(uint8_t count_, PfnCoroutine funcs[]);
void RunCoroutineSequential(uint8_t count_, PfnCoroutine funcs[]);
#endif // COROUTINES_MGR_V2_H_INCLUDED
