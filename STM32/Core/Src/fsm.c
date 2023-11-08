/*
 * fsm.c
 *
 *  Created on: Nov 8, 2023
 *      Author: dell
 */

#include "main.h"
#include "software_timer.h"
#include "button.h"
#include "fsm.h"

int counter1 = 0;
int counter2 = 0;
int redDuration = 5;
int amberDuration = 2;
int greenDuration = 3;

int status;

void clearAllLed() {
	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_SET);
}

void display7SEG1(int num) {
	switch(num) {
		case 0:
			HAL_GPIO_WritePin(GPIOB, a1_Pin|b1_Pin|c1_Pin|d1_Pin
			                          |e1_Pin|f1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, g1_Pin, GPIO_PIN_SET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOB, b1_Pin|c1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, a1_Pin|d1_Pin
		              	  	  	  	  |e1_Pin|f1_Pin|g1_Pin, GPIO_PIN_SET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOB, a1_Pin|b1_Pin|d1_Pin
			                          |e1_Pin|g1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, c1_Pin|f1_Pin, GPIO_PIN_SET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOB, a1_Pin|b1_Pin|c1_Pin
			                          |d1_Pin|g1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, e1_Pin|f1_Pin, GPIO_PIN_SET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOB, b1_Pin|c1_Pin|f1_Pin|g1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, a1_Pin|d1_Pin|e1_Pin, GPIO_PIN_SET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOB, a1_Pin|c1_Pin|d1_Pin
			                          |f1_Pin|g1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, b1_Pin|e1_Pin, GPIO_PIN_SET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOB, a1_Pin|c1_Pin|d1_Pin
			                          |e1_Pin|f1_Pin|g1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, b1_Pin, GPIO_PIN_SET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOB, a1_Pin|b1_Pin|c1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, d1_Pin|e1_Pin
									 |f1_Pin|g1_Pin, GPIO_PIN_SET);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOB, a1_Pin|b1_Pin|c1_Pin|d1_Pin
			                          |e1_Pin|f1_Pin|g1_Pin, GPIO_PIN_RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOB, a1_Pin|b1_Pin|c1_Pin|d1_Pin
			                          |f1_Pin|g1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, e1_Pin, GPIO_PIN_SET);
			break;
		default:
			break;
	}
}

void display7SEG2(int num) {
	switch(num) {
		case 0:
			HAL_GPIO_WritePin(GPIOB, a2_Pin|b2_Pin|c2_Pin|d2_Pin
			                          |e2_Pin|f2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, g2_Pin, GPIO_PIN_SET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOB, b2_Pin|c2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, a2_Pin|d2_Pin
		              	  	  	  	  |e2_Pin|f2_Pin|g2_Pin, GPIO_PIN_SET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOB, a2_Pin|b2_Pin|d2_Pin
			                          |e2_Pin|g2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, c2_Pin|f2_Pin, GPIO_PIN_SET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOB, a2_Pin|b2_Pin|c2_Pin
			                          |d2_Pin|g2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, e2_Pin|f2_Pin, GPIO_PIN_SET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOB, b2_Pin|c2_Pin|f2_Pin|g2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, a2_Pin|d2_Pin|e2_Pin, GPIO_PIN_SET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOB, a2_Pin|c2_Pin|d2_Pin
			                          |f2_Pin|g2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, b2_Pin|e2_Pin, GPIO_PIN_SET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOB, a2_Pin|c2_Pin|d2_Pin
			                          |e2_Pin|f2_Pin|g2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, b2_Pin, GPIO_PIN_SET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOB, a2_Pin|b2_Pin|c2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, d2_Pin|e2_Pin
									 |f2_Pin|g2_Pin, GPIO_PIN_SET);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOB, a2_Pin|b2_Pin|c2_Pin|d2_Pin
			                          |e2_Pin|f2_Pin|g2_Pin, GPIO_PIN_RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOB, a2_Pin|b2_Pin|c2_Pin|d2_Pin
			                          |f2_Pin|g2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, e2_Pin, GPIO_PIN_SET);
			break;
		default:
			break;
	}
}


void fsm_automatic_run() {
	switch(status) {
		case INIT:
			HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_SET);

	  	    HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_SET);
	  	    HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, GPIO_PIN_SET);
	  	    HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_RESET);

			status = RED_GREEN;

			counter1 = redDuration - 1;
			counter2 = greenDuration - 1;
			display7SEG1(counter1);
			display7SEG2(counter2);

			setTimer1(greenDuration * 1000); // Timer 1 for Traffic Led
			setTimer2(1000); // Timer 2 for 7SEG LED
			break;
		case RED_GREEN:
	  	    if(timer1_flag == 1) {
	  	    	//RED_GREEN -> RED_AMBER
	  	  	    HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_RESET);
	  	    	HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, GPIO_PIN_SET);
	  	    	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_SET);

	  	    	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_SET);
	  	  	    HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, GPIO_PIN_RESET);
	  	  	    HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_SET);

	  	  	    status = RED_AMBER;

	  	  	    counter1 = amberDuration;
	  	  	    counter2 = amberDuration;

	  	    	setTimer1(amberDuration * 1000);
	  	    }
	  	    if(timer2_flag == 1) {
	  	    	counter1--;
	  	    	counter2--;
	  	    	display7SEG1(counter1);
	  	    	display7SEG2(counter2);

	  	    	setTimer2(1000);
	  	    }
			break;
		case RED_AMBER:
	  	    if(timer1_flag == 1) {
	  	    	// RED_AMBER -> GREEN_RED
	  	  	    HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
	  	    	HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, GPIO_PIN_SET);
	  	    	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_RESET);

	  	    	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_RESET);
	  	  	    HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, GPIO_PIN_SET);
	  	  	    HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_SET);

	  	  	    status = GREEN_RED;

	  	  	    counter1 = greenDuration;
	  	  	    counter2 = redDuration;

	  	    	setTimer1(greenDuration * 1000);
	  	    }
	  	    if(timer2_flag == 1) {
	  	    	counter1--;
	  	    	counter2--;
	  	    	display7SEG1(counter1);
	  	    	display7SEG2(counter2);

	  	    	setTimer2(1000);
	  	    }
			break;
		case GREEN_RED:
	  	    if(timer1_flag == 1) {
	  	    	// GREEN_RED -> AMBER_RED
	  	  	    HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
	  	    	HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, GPIO_PIN_RESET);
	  	    	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_SET);

	  	    	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_RESET);
	  	  	    HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, GPIO_PIN_SET);
	  	  	    HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_SET);

	  	  	    status = AMBER_RED;

	  	  	    counter1 = amberDuration;
	  	  	    counter2 = amberDuration;

	  	    	setTimer1(amberDuration * 1000);
	  	    }
	  	    if(timer2_flag == 1) {
	  	    	counter1--;
	  	    	counter2--;
	  	    	display7SEG1(counter1);
	  	    	display7SEG2(counter2);

	  	    	setTimer2(1000);
	  	    }
			break;
		case AMBER_RED:
	  	    if(timer1_flag == 1) {
	  	    	// AMBER_RED -> RED_GREEN
	  	  	    HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_RESET);
	  	    	HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, GPIO_PIN_SET);
	  	    	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_SET);

	  	    	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_SET);
	  	  	    HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, GPIO_PIN_SET);
	  	  	    HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_RESET);

	  	  	    status = RED_GREEN;

	  	  	    counter1 = greenDuration;
	  	  	    counter2 = greenDuration;

	  	    	setTimer1(greenDuration * 1000);
	  	    }
	  	    if(timer2_flag == 1) {
	  	    	counter1--;
	  	    	counter2--;
	  	    	display7SEG1(counter1);
	  	    	display7SEG2(counter2);

	  	    	setTimer2(1000);
	  	    }
			break;
		case RED_MODIFY:
			break;
		case AMBER_MODIFY:
			break;
		case GREEN_MODIFY:
			break;
		default:
			break;
	}
}
