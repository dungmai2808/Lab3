/*
 * button.c
 *
 *  Created on: Nov 7, 2023
 *      Author: dell
 */


#include "button.h"
#include "main.h"

// index 0 for button 1; index 1 for button 2; index 2 for button 3

int keyReg0[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyReg1[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyReg2[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyReg3[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int TimeOutForKeyPress[3] =  {200, 200, 200}; // 200 is 2 second

int button_flag[3] = {0, 0, 0};

int isButton1Pressed(){
	if(button_flag[0] == 1){
		button_flag[0] = 0;
		return 1;
	}
	return 0;
}
int isButton2Pressed(){
	if(button_flag[1] == 1){
		button_flag[1] = 0;
		return 1;
	}
	return 0;
}
int isButton3Pressed(){
	if(button_flag[2] == 1){
		button_flag[2] = 0;
		return 1;
	}
	return 0;
}

void getKeyInput() {
	//button1
	keyReg2[0] = keyReg1[0];
	keyReg1[0] = keyReg0[0];
	keyReg0[0] = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
	//button2
	keyReg2[1] = keyReg1[1];
	keyReg1[1] = keyReg0[1];
	keyReg0[1] = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);
	//button3
	keyReg2[2] = keyReg1[2];
	keyReg1[2] = keyReg0[2];
	keyReg0[2] = HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin);

	for(int i = 0; i < 3; i++) {
		if((keyReg0[i] == keyReg1[i]) && (keyReg1[i] == keyReg2[i])) {
			if(keyReg3[i] != keyReg2[i]) {
				keyReg3[i] = keyReg2[i];
				if(keyReg3[i] == PRESS_STATE) {
					button_flag[i] = 1;
					TimeOutForKeyPress[i] = 200;
				}
			}
			else {
				TimeOutForKeyPress[i]--;
				if(TimeOutForKeyPress[i] == 0) {
					TimeOutForKeyPress[i] = 200;
					if(keyReg3[i] == PRESS_STATE) {
						button_flag[i] = 1;
					}
				}
			}
		}
	}
}
