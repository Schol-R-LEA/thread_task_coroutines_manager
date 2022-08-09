#ifndef THREAD_TASK_MGR_H_INCLUDED
#define THREAD_TASK_MGR_H_INCLUDED
////////////////////////////////////////////////////////////////////////////////////////////
// libraries

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>

//////////////////////////////////////////////////////////////////////////////////
// definitions

/// Basic function state check
#define                                 \
    FunctionStart                       \
    static int state = 0;               \
    switch(state)                       \
    {                                   \
        case 0:

#define 								\
    FunctionCheck(bit, bit_state)		\
        case __LINE__:			        \
        if(bit == bit_state)            \
        {                               \
            printf("FunctionCheck true, func# %s, line# %d\n\n",__func__, __LINE__);  \
            state = __LINE__;			\
            return 1;                   \
        }                               \
        else{                           \
            printf("FunctionCheck false, func# %s, line# %d\n\n",__func__, __LINE__); \
            return 0;                   \
        }

#define                                 \
    FunctionEnd                         \
    }                                   \
    state = 0; 					        \
    printf("FUNC DONE# %s\n", __func__)

/// Task sequence manager
#define                                 \
    TaskStart(Task)                     \
    Task = 0;                           \
    static int state = 0;               \
    switch(state)                       \
    {                                   \
        case 0:

#define 								\
    CheckBit(bit, bit_state)			\
    do									\
    {									\
        case __LINE__:			        \
        if(bit == bit_state)            \
        {                               \
            printf("CheckBit true\n");  \
            state = __LINE__;			\
            break;                      \
        }                               \
        else{                           \
            printf("CheckBit false\n"); \
        }                               \
    }while(0)

#define                                 \
    TaskEnd                             \
    }                                   \
    state = 0; 					        \
    printf("TASK DONE# %s\n", __func__)

//////////////////////////////////////////////////////////////////////////////////
// enumerations

// function pointer

// pointers

// variables

//////////////////////////////////////////////////////////////////////////////////
// functions

#endif // THREAD_TASK_MGR_H_INCLUDED
