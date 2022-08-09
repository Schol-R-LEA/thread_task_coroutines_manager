#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "../coroutines_mgr_v2/coroutines_mgr_v2.h"
#include "../thread_task_mgr/thread_task_mgr.h"
#include "modules.h"

bool SSP1CON2bits_SEN1;
bool SSP1STATbits_RW1;

static unsigned long start_millis = 0;


bool i2c_write(void){
    FunctionStart;
    SSP1CON2bits_SEN1 = 1;

    printf("SSP1CON2bits_SEN1 ### SET ### %d\n", SSP1CON2bits_SEN1);
    FunctionCheck(SSP1CON2bits_SEN1, true);
    printf("SSP1CON2bits_SEN1 ### CLEARED ### %d\n", SSP1CON2bits_SEN1);


    SSP1STATbits_RW1 = 1;
    printf("SSP1STATbits_RW1 ### SET ### %d\n", SSP1STATbits_RW1);
    FunctionCheck(SSP1STATbits_RW1, true);
    printf("SSP1STATbits_RW1 ### CLEARED ### %d\n", SSP1STATbits_RW1);

    FunctionEnd;
    return 0;
}

void start_time(void){
    start_millis = millis();
}


bool i2c_bit_set_clear_routine(void){

    printf("i2c_bit_set_clear_routine\n");

    if(millis() - start_millis > 1000){
        printf("time difference %lu\n", millis() - start_millis);

        printf("---------------------------------------------------------------\n");
        printf("---------------------------------------------------------------\n");

        printf("bits cleared ===========================\n");
        SSP1CON2bits_SEN1 = 0;
        SSP1STATbits_RW1 = 0;
        start_millis = millis();
        return 0;
    }
    return 1;
}

bool function1(void){
    BeginCoroutine;
    printf("\n1 part1 %d\n", __LINE__ + 1);
    CoroutineDelay(200);
    printf("\n1 part2 %d\n", __LINE__ + 1);
    CoroutineDelay(30);
    printf("\n1 part3 %d\n", __LINE__ + 1);
    CoroutineDelay(50);
    printf("\n1 part4 %d\n", __LINE__ + 1);
    CoroutineDelay(10);
    EndCoroutine;
}

bool function2(void){
    BeginCoroutine;
    printf("\n2 part1 %d\n", __LINE__ + 1);
    CoroutineDelay(50);
    printf("\n2 part2 %d\n", __LINE__ + 1);
    CoroutineDelay(10);
    printf("\n2 part3 %d\n", __LINE__ + 1);
    CoroutineDelay(50);
    printf("\n2 part4 %d\n", __LINE__ + 1);
    CoroutineDelay(10);
    EndCoroutine;
}

bool function3(void){
    BeginCoroutine;
    printf("\n3 part1 %d\n", __LINE__ + 1);
    CoroutineDelay(100);
    printf("\n3 part2 %d\n", __LINE__ + 1);
    CoroutineDelay(200);
    EndCoroutine;
}

bool function4(void){
    BeginCoroutine;
    printf("\n4 part1 %d\n", __LINE__ + 1);
    CoroutineDelay(500);
    printf("\n4 part2 %d\n", __LINE__ + 1);
    CoroutineDelay(50);
    EndCoroutine;
}


