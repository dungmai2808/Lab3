/*
 * button.h
 *
 *  Created on: Nov 7, 2023
 *      Author: dell
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NORMAL_STATE GPIO_PIN_SET
#define PRESS_STATE GPIO_PIN_RESET

void getKeyInput();
int isButton1Pressed();
int isButton2Pressed();
int isButton3Pressed();

#endif /* INC_BUTTON_H_ */
