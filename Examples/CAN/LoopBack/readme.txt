/*!
 * @file        readme.txt
 *
 * @brief       This file is routine instruction
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


&par Example Description

This example describes how to config a communication the CAN in loopback mode.
CAN transmit a message to self. Then compare the received message with transmitted
message.
  - Polling transmit success: The LED2 turns, otherwise LED2 turns off.
  - Interrupt transmit success: The LED3 turns, otherwise LED3 turns off.

&par Directory contents

  - CAN/LoopBack/src/apm32f10x_int.c     Interrupt handlers
  - CAN/LoopBack/src/main.c                      Main program


&par Hardware and Software environment

  - This example runs on APM32F103_MINI Devices.