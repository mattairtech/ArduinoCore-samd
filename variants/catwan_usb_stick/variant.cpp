/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "variant.h"

/*
 * Pins descriptions
 */
const PinDescription g_APinDescription[]=
{
 
  // 0 - Connected to radio DIO0 external interrupt 4 
  { PORTA, 4, PIO_MULTI, (PER_ATTR_DRIVE_STD), (PIN_ATTR_DIGITAL), TCC0_CH1, No_ADC_Channel, EXTERNAL_INT_4, GCLK_CCL_NONE }, // TCC0/WO[1]

  // 1 - Connected to radio DIO1 //RFM_RST
  { PORTA, 23, PIO_MULTI, PER_ATTR_DRIVE_STD, PIN_ATTR_DIGITAL, NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_2, GCLK_CCL_NONE }, // ADC/AIN[0]

  // 2 - Connected to radio DIO2
  { PORTA, 27, PIO_MULTI, PER_ATTR_DRIVE_STD, PIN_ATTR_DIGITAL, NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE },  // TCC0/WO[0]

  // 3 - SERCOM1 - PA00 - TX and GPIO    ADC, DAC, IRQ, Captouch and general purpose pin - no timer
  { PORTA,  0, PIO_MULTI, (PER_ATTR_DRIVE_STD), (PIN_ATTR_DIGITAL|PIN_ATTR_SERCOM), TCC2_CH0, No_ADC_Channel, EXTERNAL_INT_0, GCLK_CCL_NONE }, // 
  // 4 - SERCOM1 - PA01 - RX and GPIO
  { PORTA,  1, PIO_MULTI, (PER_ATTR_DRIVE_STD), (PIN_ATTR_DIGITAL|PIN_ATTR_SERCOM|PIN_ATTR_TIMER), TCC2_CH1, No_ADC_Channel, EXTERNAL_INT_1, GCLK_CCL_NONE },  // TCC0/WO[0]
   
  // 5 - GPIO 
  { PORTA, 28, PIO_MULTI, PER_ATTR_DRIVE_STD, (PIN_ATTR_DIGITAL|PIN_ATTR_COM), NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // USB Host enable - GPIO #5

  // GPIO 6, 7 (USB interface)
  // ----------------------------
  { PORTA, 24, PIO_MULTI, PER_ATTR_DRIVE_STD, (PIN_ATTR_DIGITAL|PIN_ATTR_COM), NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // USB/DM - GPIO #6
  { PORTA, 25, PIO_MULTI, PER_ATTR_DRIVE_STD, (PIN_ATTR_DIGITAL|PIN_ATTR_COM), NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // USB/DP - GPIO #7

  // GPIO 8, 9, 10 - analog inputs which are 'clones' of the analog pins
  // A0 
  { PORTA,  2, PIO_MULTI, PER_ATTR_DRIVE_STD, PIN_ATTR_DIGITAL, NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // ADC/AIN[0]
  // A1 
  { PORTA, 16, PIO_MULTI, PER_ATTR_DRIVE_STD, PIN_ATTR_NONE, NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // TCC0/WO[1]
  // DIO0 
  { PORTA, 11, PIO_MULTI, PER_ATTR_DRIVE_STD, PIN_ATTR_DIGITAL, NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_11, GCLK_CCL_NONE },  // TCC0/WO[0]

  // GPIO 11 & 12 (SWCLK & SWDIO)
  // --------------------------
  { PORTA, 30, PIO_MULTI, PER_ATTR_DRIVE_STD, PIN_ATTR_DIGITAL, NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE },
  { PORTA, 31, PIO_MULTI, PER_ATTR_DRIVE_STD, PIN_ATTR_DIGITAL, NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE },

  // GPIO 13 (LED)
  { PORTA, 14, PIO_MULTI, PER_ATTR_DRIVE_STD, PIN_ATTR_DIGITAL, NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_7, GCLK_CCL_NONE }, // Digital #13

  // Placeholder #14 & 15 for 'txled'
  { PORTA, 10, PIO_MULTI, PER_ATTR_DRIVE_STD, PIN_ATTR_DIGITAL, NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_10, GCLK_CCL_NONE },
  { PORTA, 15, PIO_MULTI, PER_ATTR_DRIVE_STD, PIN_ATTR_DIGITAL, NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE },

  // Placeholder #16 - extra Sercom/SPI pin that doesnt actually get used
  { PORTA, 20, PIO_MULTI, PER_ATTR_DRIVE_STD, PIN_ATTR_NONE, NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // TCC0/WO[1]

  //17,18,19,20 SPI= MISO-PA22, MOSI-PA18, SCK-PA19, SS-PA23 
  { PORTA, 22, PIO_SERCOM, (PER_ATTR_SERCOM_STD), (PIN_ATTR_DIGITAL|PIN_ATTR_SERCOM), NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, 
	{ PORTA, 18, PIO_SERCOM, (PER_ATTR_SERCOM_ALT), (PIN_ATTR_DIGITAL|PIN_ATTR_SERCOM), NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE },
	{ PORTA, 19, PIO_SERCOM, (PER_ATTR_SERCOM_ALT), (PIN_ATTR_DIGITAL|PIN_ATTR_SERCOM), NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE },
	{ PORTA, 17, PIO_SERCOM, (PER_ATTR_SERCOM_STD), (PIN_ATTR_DIGITAL|PIN_ATTR_SERCOM), NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE },

  // For unknown reasons we need to have gpio 21-24 so here are extra pins (shrug)
  { PORTA, 8, PIO_MULTI, PER_ATTR_DRIVE_STD, PIN_ATTR_DIGITAL, NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_14, GCLK_CCL_NONE },
  { PORTA, 9, PIO_MULTI, (PER_ATTR_DRIVE_STD|PER_ATTR_TIMER_STD), (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER), TC3_CH1, No_ADC_Channel, EXTERNAL_INT_15, GCLK_CCL_NONE },
  { PORTA, 16, PIO_MULTI, (PER_ATTR_DRIVE_STD|PER_ATTR_TIMER_STD), (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER), TCC2_CH0, No_ADC_Channel, EXTERNAL_INT_0, GCLK_CCL_NONE }, // TCC2/WO[0]
  { PORTA,  6, PIO_MULTI, (PER_ATTR_DRIVE_STD|PER_ATTR_TIMER_STD), (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER), TCC2_CH1, No_ADC_Channel, EXTERNAL_INT_1, GCLK_CCL_NONE }, // TCC2/WO[1]
} ;

const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ TCC0, TCC1, TCC2, TC3, TC4, TC5 } ;

// Multi-serial objects instantiation
SERCOM sercom0( SERCOM0 ) ;
SERCOM sercom1( SERCOM1 ) ;
SERCOM sercom2( SERCOM2 ) ;
SERCOM sercom3( SERCOM3 ) ;
Uart Serial1( &sercom1, PIN_SERIAL1_RX, PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX ) ;


// If wire.h isnt included, just do nothing
void WIRE_IT_HANDLER(void) __attribute__ ((weak));

void SERCOM1_Handler(void) __attribute__((weak));
void SERCOM1_Handler()
{
  Serial1.IrqHandler();
}

