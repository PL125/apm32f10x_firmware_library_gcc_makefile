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

This example shows how to configure the DMA peripheral to transmit data from
momery to momery. After system reset, data transmit form one group to another
through DMA. If the data received is equal to the data send, LED2 will light,
otherwise, LED3 will light.

&par Directory contents

  - DMA/MomeryToMomery/src/apm32f10x_int.c     Interrupt handlers
  - DMA/MomeryToMomery/src/main.c                     Main program


&par Hardware and Software environment

  - This example runs on APM32F103_MINI Devices.