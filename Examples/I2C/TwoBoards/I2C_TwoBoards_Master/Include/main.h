/*!
 * @file        main.h
 *
 * @brief       Main program body
 *
 * @version     V1.0.2
 *
 * @date        2022-01-05
 *
 * @attention
 *
 *  Copyright (C) 2020-2022 Geehy Semiconductor
 *
 *  You may not use this file except in compliance with the
 *  GEEHY COPYRIGHT NOTICE (GEEHY SOFTWARE PACKAGE LICENSE).
 *
 *  The program is only for reference, which is distributed in the hope
 *  that it will be usefull and instructional for customers to develop
 *  their software. Unless required by applicable law or agreed to in
 *  writing, the program is distributed on an "AS IS" BASIS, WITHOUT
 *  ANY WARRANTY OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the GEEHY SOFTWARE PACKAGE LICENSE for the governing permissions
 *  and limitations under the License.
 */

#ifndef __MAIN_H
#define __MAIN_H

#include <stdio.h>
#include "Board.h"
#include "apm32f10x_i2c.h"

void Delay(void);
void USART_Init(void);

/** I2C Init */
void I2C_Init(void);
/** I2C Write */
uint8_t I2C_Write(char * pBuffer);
/** I2C Interrupt */
void APM_MINI_PB_I2C_Isr(void);
void I2C_Isr(void);

#endif

