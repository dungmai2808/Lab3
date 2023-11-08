/*
 * fsm.h
 *
 *  Created on: Nov 8, 2023
 *      Author: dell
 */

#ifndef INC_FSM_H_
#define INC_FSM_H_

#define INIT			0
#define RED_GREEN		1
#define RED_AMBER		2
#define GREEN_RED		3
#define	AMBER_RED		4
#define RED_MODIFY		5
#define AMBER_MODIFY	6
#define GREEN_MODIFY	7

extern int status;
void fsm_automatic_run();

#endif /* INC_FSM_H_ */
