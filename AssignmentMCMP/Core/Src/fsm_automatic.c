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
int pedeson=0;

void fsm_automatic_run(){
	switch(status) {
		case INIT:
			status = RED_GREEN;
			setInitialValue(red_duration, green_duration);
			setTimer(green_duration*100, 0);
			setTimer(100, 1);
			break;
		case RED_GREEN:
			setHorizontalLeds(SET,RESET,RESET);	//D4-5 horizontal
			setVerticalLeds(RESET,SET, RESET);
			if(timer_flag[9]==1){
				pedeson=0;
				setPedesLeds(RESET, RESET, RESET);
			}
			if(pedeson==1){
				setPedesLeds(RESET, SET, RESET);
			}
			if(timer_flag[0] == 1){
				setPedesLeds(RESET,RESET,RESET);
				setTimer(yellow_duration*100, 0);
				setHorizontalLeds(RESET,RESET,RESET); //D4-5 horizontal
				setVerticalLeds(RESET,RESET, RESET);
				status = RED_YELLOW;
				setInitialValue(yellow_duration, yellow_duration);
			}
			if(timer_flag[1] == 1){
				countDown();
				setTimer(100, 1);
			}
			if(isButtonPressed(1) == 1){
				setHorizontalLeds(RESET,RESET,RESET);
				setVerticalLeds(RESET,RESET, RESET);
				setPedesLeds(RESET,RESET,RESET);
				setTimer(100, 3);
				status = MAN_RED;
			}
			if(isButtonPressed(0) == 1){
				setPedesLeds(RESET,SET,RESET);
				pedeson=1;
				int pedesduration = (red_duration+green_duration+yellow_duration)*100;
				setTimer(pedesduration,9);
			}
			break;
		case RED_YELLOW:
			setHorizontalLeds(SET,RESET,RESET);
			setVerticalLeds(RESET,RESET, SET);
			if(timer_flag[9]==1){
				pedeson=0;
				setPedesLeds(RESET, RESET, RESET);
			}
			if(pedeson==1){
				setPedesLeds(RESET, SET, RESET);
			}
			if(timer_flag[0] == 1){
				setPedesLeds(RESET,RESET,RESET);
				setTimer(green_duration*100, 0);
				status = GREEN_RED;
				setInitialValue(green_duration, red_duration);
				setHorizontalLeds(RESET,RESET,RESET); //D4-5 horizontal
				setVerticalLeds(RESET,RESET, RESET);
			}
			if(timer_flag[1] == 1){
				countDown();
				setTimer(100, 1);
			}
			if(isButtonPressed(0) == 1){
				setPedesLeds(RESET,SET,RESET);
				pedeson=1;
				int pedesduration = (red_duration+green_duration+yellow_duration)*100;
				setTimer(pedesduration,9);
			}
			break;
		case GREEN_RED:
			setHorizontalLeds(RESET,SET,RESET);
			setVerticalLeds(SET,RESET,RESET);
			if(timer_flag[9]==1){
				pedeson=0;
				setPedesLeds(RESET, RESET, RESET);
			}
			if(pedeson==1){
				setPedesLeds(SET, RESET, RESET);
			}
			if(timer_flag[0] == 1){
				setPedesLeds(RESET,RESET,RESET);
				setTimer(yellow_duration*100, 0);
				status = YELLOW_RED;
				setInitialValue(yellow_duration, yellow_duration);
				setHorizontalLeds(RESET,RESET,RESET); //D4-5 horizontal
				setVerticalLeds(RESET,RESET, RESET);
			}
			if(timer_flag[1] == 1){
				countDown();
				setTimer(100, 1);
			}
			if(isButtonPressed(0) == 1){
				setPedesLeds(SET,RESET,RESET);
				pedeson=1;
				int pedesduration = (red_duration+green_duration+yellow_duration)*100;
				setTimer(pedesduration,9);
			}
			break;
		case YELLOW_RED:
			setHorizontalLeds(RESET,RESET,SET);
			setVerticalLeds(SET,RESET,RESET);
			if(timer_flag[9]==1){
				pedeson=0;
				setPedesLeds(RESET, RESET, RESET);
			}
			if(pedeson==1){
				setPedesLeds(SET, RESET, RESET);
			}
			if(timer_flag[0] == 1){
				setPedesLeds(RESET,RESET,RESET);
				setTimer(green_duration*100, 0);
				status = RED_GREEN;
				setInitialValue(red_duration, green_duration);
				setHorizontalLeds(RESET,RESET,RESET); //D4-5 horizontal
				setVerticalLeds(RESET,RESET, RESET);
			}
			if(timer_flag[1] == 1){
				countDown();
				setTimer(100, 1);
			}
			if(isButtonPressed(0) == 1){
				setPedesLeds(SET,RESET,RESET);
				pedeson=1;
				int pedesduration = (red_duration+green_duration+yellow_duration)*100;
				setTimer(pedesduration,9);
			}
			break;
		default:
			break;
	}
};
