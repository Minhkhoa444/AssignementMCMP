/*
 * fsm_automatic.c
 *
 *  Created on: Nov 27, 2023
 *      Author: Admin
 */


#include "fsm_automatic.h"

int red_duration = 5;
int green_duration = 3;
int yellow_duration = 2;
int index_led = 0;


void fsm_automatic_run(){
	switch(status) {
		case INIT:
			status = RED_GREEN;
			setTimer(green_duration*1000, 0);
			setTimer(1000, 1);
			break;
		case RED_GREEN:
			setHorizontalLeds(SET,RESET,RESET);
			setVerticalLeds(RESET,SET, RESET);

			if(timer_flag[0] == 1){
				setPedesLeds(RESET,RESET,RESET);
				setTimer(yellow_duration*1000, 0);
				status = RED_YELLOW;
			}
			if(timer_flag[1] == 1){
				countDown();
				setTimer(1000, 1);
			}
			if(isButtonPressed(1) == 1){
				setHorizontalLeds(RESET,RESET,RESET);
				setVerticalLeds(RESET,RESET, RESET);
				setPedesLeds(RESET,RESET,RESET);
				setTimer(1000, 3);
				status = MAN_RED;
			}
			if(isButtonPressed(0) == 1){
				setPedesLeds(RESET,SET,RESET);
			}
			break;
		case RED_YELLOW:
			setHorizontalLeds(SET,RESET,RESET);
			setVerticalLeds(RESET,RESET, SET);
			if(timer_flag[0] == 1){
				setPedesLeds(RESET,RESET,RESET);
				setTimer(green_duration*1000, 0);
				status = GREEN_RED;
			}
			if(timer_flag[1] == 1){
				countDown();
				setTimer(1000, 1);
			}
			if(isButtonPressed(0) == 1){
				setPedesLeds(RESET,SET,RESET);
			}
			break;
		case GREEN_RED:
			setHorizontalLeds(RESET,SET,RESET);
			setVerticalLeds(SET,RESET,RESET);
			if(timer_flag[0] == 1){
				setPedesLeds(RESET,RESET,RESET);
				setTimer(yellow_duration*1000, 0);
				status = YELLOW_RED;
			}
			if(timer_flag[1] == 1){
				countDown();
				setTimer(1000, 1);
			}
			if(isButtonPressed(0) == 1){
				setPedesLeds(SET,RESET,RESET);
			}
			break;
		case YELLOW_RED:
			setHorizontalLeds(RESET,RESET,SET);
			setVerticalLeds(SET,RESET,RESET);
			if(timer_flag[0] == 1){
				setPedesLeds(RESET,RESET,RESET);
				setTimer(green_duration*1000, 0);
				status = RED_GREEN;
			}
			if(timer_flag[1] == 1){
				countDown();
				setTimer(1000, 1);
			}
			if(isButtonPressed(0) == 1){
				setPedesLeds(SET,RESET,RESET);
			}
			break;
		default:
			break;
	}


};
