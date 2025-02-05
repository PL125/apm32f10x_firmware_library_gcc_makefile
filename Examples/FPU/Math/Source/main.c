/*!
 * @file        main.c
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

#include "main.h"

/** printf function configs to USART1*/
#define DEBUG_USART  USART1

float a, b, s, x, y, z, ans[100], X[100] = {0, 0, 0,};
float PI = 3.14159;

uint8_t databuff;

/*!
 * @brief       Main program
 *
 * @param       None
 *
 * @retval      None
 *
 */
int main(void)
{
    GPIO_Config_T GPIO_ConfigStruct;
    USART_Config_T USART_ConfigStruct;

    RCM_EnableAHBPeriphClock(RCM_AHB_PERIPH_FPU);
    RCM->CFG |= BIT27;    // RCM->CFG |= (1 << 27);    // RCM->CFG |= (uint32_t) (1 << 27);    // RCM->CFG |= (uint32_t) (1ULL << 27);

    RCM_EnableAPB2PeriphClock((RCM_APB2_PERIPH_T)(RCM_APB2_PERIPH_GPIOA | RCM_APB2_PERIPH_USART1));

    GPIO_ConfigStruct.mode = GPIO_MODE_AF_PP;
    GPIO_ConfigStruct.pin = GPIO_PIN_9;
    GPIO_ConfigStruct.speed = GPIO_SPEED_50MHz;
    GPIO_Config(GPIOA, &GPIO_ConfigStruct);

    USART_ConfigStruct.baudRate = 115200;
    USART_ConfigStruct.hardwareFlow = USART_HARDWARE_FLOW_NONE;
    USART_ConfigStruct.mode = USART_MODE_TX;
    USART_ConfigStruct.parity = USART_PARITY_NONE;
    USART_ConfigStruct.stopBits = USART_STOP_BIT_1;
    USART_ConfigStruct.wordLength = USART_WORD_LEN_8B;
    USART_Config(USART1, &USART_ConfigStruct);

    USART_Enable(USART1);

    printf("SIN:");

    for (s = 0; s < 100; s++)
    {
        ans[databuff] = 0x00;
        databuff++;
    }

    databuff = 0;

    for (s = -PI; s < 0; s = s + 0.1)
    {
        ans[databuff] = sc_math_sin(s);
        databuff++;
    }

    ans[databuff] = sc_math_sin(0);
    databuff++;

    for (s = PI; s > 0; s = s - 0.1)
    {
        ans[databuff] = sc_math_sin(s);
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        printf("%5.11f\n", ans[databuff]);
        databuff++;
    }

    printf("\n");
    printf("\n");
    printf("COS:\n");

    for (s = 0; s < 100; s++)
    {
        ans[databuff] = 0x00;
        databuff++;
    }

    databuff = 0;

    for (s = -PI; s < 0; s = s + 0.1)
    {
        ans[databuff] = sc_math_cos(s);
        databuff++;
    }

    ans[databuff] = sc_math_cos(0);
    databuff++;

    for (s = PI; s > 0; s = s - 0.1)
    {
        ans[databuff] = sc_math_cos(s);
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        printf("%5.11f\n", ans[databuff]);
        databuff++;
    }

    printf("\n");
    printf("\n");
    printf("TAN:\n");

    for (s = 0; s < 100; s++)
    {
        ans[databuff] = 0x00;
        databuff++;
    }

    databuff = 0;

    for (s = -PI; s < 0; s = s + 0.1)
    {
        ans[databuff] = sc_math_tan(s);
        databuff++;
    }

    ans[databuff] = sc_math_tan(0);
    databuff++;

    for (s = PI; s > 0; s = s - 0.1)
    {
        ans[databuff] = sc_math_tan(s);
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        printf("%5.11f\n", ans[databuff]);
        databuff++;
    }

    printf("\n");
    printf("\n");
    printf("ATAN:\n");

    for (s = 0; s < 100; s++)
    {
        ans[databuff] = 0x00;
        databuff++;
    }

    databuff = 0;

    for (s = -PI; s < 0; s = s + 0.1)
    {
        ans[databuff] = sc_math_atan(s);
        databuff++;
    }

    ans[databuff] = sc_math_atan(0);
    databuff++;

    for (s = PI; s > 0; s = s - 0.1)
    {
        ans[databuff] = sc_math_atan(s);
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        printf("%5.11f\n", ans[databuff]);
        databuff++;
    }

    printf("\n");
    printf("\n");
    printf("ASIN:\n");

    for (s = 0; s < 100; s++)
    {
        ans[databuff] = 0x00;
        databuff++;
    }

    databuff = 0;

    for (s = -1; s <= 1; s = s + 0.1)
    {
        ans[databuff] = sc_math_asin(s);
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        printf("%5.11f\n", ans[databuff]);
        databuff++;
    }

    printf("\n");
    printf("\n");
    printf("ACOS:\n");

    for (s = 0; s < 100; s++)
    {
        ans[databuff] = 0x00;
        databuff++;
    }

    databuff = 0;

    for (s = -1; s <= 1; s = s + 0.1)
    {
        ans[databuff] = sc_math_acos(s);
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        printf("%5.11f\n", ans[databuff]);
        databuff++;
    }

    printf("\n");
    printf("\n");
    printf("ATAN2:\n");

    for (s = 0; s < 100; s++)
    {
        ans[databuff] = 0x00;
        databuff++;
    }

    databuff = 0;

    for (s = -PI; s < 0; s = s + 0.1)
    {
        a = s;
        b = s + 0.1;
        ans[databuff] = sc_math_atan2(b, a);
        databuff++;
    }

    a = s;
    b = s + 0.1;
    ans[databuff] = sc_math_atan2(0, 0);
    databuff++;


    for (s = PI; s > 0; s = s - 0.1)
    {
        a = s;
        b = s - 0.1;
        ans[databuff] = sc_math_atan2(b, a);
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        printf("%5.11f\n", ans[databuff]);
        databuff++;
    }

    printf("\n");
    printf("\n");
    printf("invsqrt:\n");
    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        ans[databuff] = sc_math_invsqrt(databuff);
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        printf("%5.11f\n", ans[databuff]);
        databuff++;
    }

    printf("\n");
    printf("\n");
    printf("mac:\n");

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        x = s;
        y = s + 1;
        z = s + 2;
        ans[databuff] = sc_math_mac(x, y, z);
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        printf("%f\n", ans[databuff]);
        databuff++;
    }

    printf("\n");
    printf("\n");
    printf("sum_N:\n");
    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        X[databuff] = s;
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        ans[databuff] = sc_math_sum_N(X, databuff);
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        printf("%5.11f\n", ans[databuff]);
        databuff++;
    }

    printf("\n");
    printf("\n");
    printf("sub_N:\n");

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        X[databuff] = 100 - s;
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        ans[databuff] = sc_math_sub_N(X, databuff);
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        printf("%5.11f\n", ans[databuff]);
        databuff++;
    }

    printf("\n");
    printf("\n");
    printf("prdct:\n");

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        X[databuff] = s + 1;
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        ans[databuff] = sc_math_prdct(X, databuff);
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        printf("%5.11f\n", ans[databuff]);
        databuff++;
    }

    printf("\n");
    printf("\n");
    printf("sumsq:\n");
    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        X[databuff] = 100 - s;
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        ans[databuff] = sc_math_sumsq(X, databuff);
        databuff++;
    }

    databuff = 0;

    for (s = 0; s < 100; s++)
    {
        printf("%5.11f\n", ans[databuff]);
        databuff++;
    }

    while (1)
    {
    }
}

/*!
 * @brief       USART configs
 *
 * @param       None
 *
 * @retval      None
 *
 */
void USART_Init(void)
{
    USART_Config_T USART_ConfigStruct;

    USART_ConfigStruct.baudRate = 115200;
    USART_ConfigStruct.hardwareFlow = USART_HARDWARE_FLOW_NONE;
    USART_ConfigStruct.mode = USART_MODE_TX;
    USART_ConfigStruct.parity = USART_PARITY_NONE;
    USART_ConfigStruct.stopBits = USART_STOP_BIT_1;
    USART_ConfigStruct.wordLength = USART_WORD_LEN_8B;

    APM_MINI_COMInit(COM1, &USART_ConfigStruct);
}

/*!
 * @brief       Redirect C Library function printf to serial port.
 *              After Redirection, you can use printf function.
 *
 * @param       ch:  The characters that need to be send.
 *
 * @param       *f:  pointer to a FILE that can recording all information
 *              needed to control a stream
 *
 * @retval      The characters that need to be send.
 *
 * @note
 */
int fputc(int ch, FILE* f)
{
    /** send a byte of data to the serial port */
    USART_TxData(DEBUG_USART, (uint8_t)ch);

    /** wait for the data to be send  */
    while (USART_ReadStatusFlag(DEBUG_USART, USART_FLAG_TXBE) == RESET);

    return (ch);
}

/*    https://www.mikrocontroller.net/topic/492672#6258842
volatile uint32_t *AHBCLKEN    = (uint32_t *)0x40021014;    // [3..3] FPU clock enable
volatile uint32_t *FPU_CFGR    = (uint32_t *)0x40021004;    // [27..27] FPUDIV

*AHBCLKEN = *AHBCLKEN  | (1<<3);
while ( (*AHBCLKEN & (1<<3)) == 0 ){};

*FPU_CFGR = *FPU_CFGR | (1<<27);
while ( (*FPU_CFGR  & (1<<27)) == 0 ){};

//volatile uint32_t *FPU_Opcode   = (uint32_t  *)0x40024000;
//*FPU_Opcode = (uint32_t)0x09;

x=0.1f;
y=sc_math_acos(x);
*/
