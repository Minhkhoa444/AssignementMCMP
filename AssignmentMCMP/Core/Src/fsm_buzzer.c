/*
 * fsm_buzzer.c
 *
 *  Created on: Dec 3, 2023
 *      Author: ADMIN
 */


#include "fsm_buzzer.h"

//uint8_t buzzer_counter = 1;

void fsm_buzzer_run(void) {
    // switch(status) {    //  timer flag 8
    //     case BUZZER:
    //         HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
    //         __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 20);
    //         HAL_Delay(1000);
    //         status = BUZZER_FAST;
    //         break;
    //     case BUZZER_FAST:
    //         __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 40);
    //         HAL_Delay(600);
    //         status = BUZZER_FASTEST;
    //         break;
    //     case BUZZER_FASTEST:
    //         __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 60);
    //         HAL_Delay(400);
    //         status = RED_GREEN;
    //         break;
    //     default:
    //         break;
    // }
    // if(status == BUZZER) {
    //     if(timer[4]_flag) {
    //         __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 20 * buzzer_counter);
    //         buzzer_counter += 1;
    //         if(buzzer_counter == 5) buzzer_counter = 1; 
    //         setTimer(x, 8);
    //     }
    // }
}