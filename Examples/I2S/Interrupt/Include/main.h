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

#include <string.h>
#include "Board.h"
#include "apm32f10x_fmc.h"
#include "apm32f10x_spi.h"

extern const uint16_t I2S3_Buffer_Tx[32];
extern uint16_t I2S2_Buffer_Rx[32];
extern volatile uint32_t txCnt;
extern volatile uint32_t rxCnt;

void RCM_Configuration(void);
void GPIO_Configuration(void);
void NVIC_Configuration(void);
uint8_t Buffercmp(uint16_t* pBuffer1, uint16_t* pBuffer2, uint16_t BufferLength);
uint8_t Buffercmp24bits(uint16_t* pBuffer1, uint16_t* pBuffer2, uint16_t BufferLength);

#endif

