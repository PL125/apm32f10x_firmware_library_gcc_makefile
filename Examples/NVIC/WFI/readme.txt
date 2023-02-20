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

This example describes how to use WFI event to enter sleep mode and wake up
using external interrupt.
At startup, press KEY2(PA0) to occur Wait For Interrupt(WFI) event, and device
will enter sleep mode. The device will wake up if press KEY2 again.

 phenomenon :
  - program running: LED2, LED3 blink.
  - sleep mode: LED2, LED3 off.

&par Directory contents

  - NVIC/WFI/src/apm32f10x_int.c     Interrupt handlers
  -NVIC/WFI/src/main.c                   Main program


&par Hardware and Software environment

  - This example runs on APM32F103 MINI Devices.
