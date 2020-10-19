/*
  xdsp_13_max7219.ino - Display MAX72xx support for Tasmota

  Copyright (C) 2020  Gerhard Mutz and Theo Arends

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

//#ifdef USE_SPI
#ifdef USE_SPI
#ifdef USE_DISPLAY
#ifdef USE_DISPLAY_max72xxp

#include <MD_Parola.h>
#include <MD_MAX72xx.h>

#warning **** MAX 72xxp ****
#define XDSP_14 14


//max72xxpPanel matrix72xx = max72xxpPanel(15, numberOfHorizontalDisplays, numberOfVerticalDisplays);

void max72xxpInitDriver() {
  if (!Settings.display_model) {
    Settings.display_model = XDSP_14;
    Serial.println("!!!DR");
  }
  if  (PinUsed(GPIO_SSPI_CS) && PinUsed(GPIO_SSPI_MOSI) && PinUsed(GPIO_SSPI_SCLK)) { //SSPI_CS D8G15 SSPI_MOSI D7 G13 SSPI_SCLK D5 G14
  //  Serial.println("!DEBAG PIN OK");
 //   matrix72xx = new max72xxpPanel(Pin(GPIO_SSPI_CS), numberOfHorizontalDisplays, numberOfVerticalDisplays);

  } else {
    if (PinUsed(GPIO_SPI_CS) && PinUsed(GPIO_SPI_MOSI) && PinUsed(GPIO_SPI_CLK)) {
      // max72xxpPanel matrix72xx = max72xxpPanel(GPIO_SPI_CS, numberOfHorizontalDisplays, numberOfVerticalDisplays);
    } else {
      return;
    }
  }


  matrix72xxInitMode();
  //  matrix72xx.setIntensity(13); // Яркость матрицы от 0 до 15



}
void matrix72xxpInitMode(void)
{
  Serial.println("!DEBAG INIT");
  
#ifdef SHOW_SPLASH

#endif

}
void max72xxpOnOff(void) {
  if (!disp_power) {
    
  }

}
void DisplayText(String text) {
  

  }
}
String utf8rus(String source)
{
  int i, k;
  String target;
  unsigned char n;
  char m[2] = { '0', '\0' };

  k = source.length(); i = 0;

  while (i < k) {
    n = source[i]; i++;

    if (n >= 0xC0) {
      switch (n) {
        case 0xD0: {
            n = source[i]; i++;
            if (n == 0x81) {
              n = 0xA8;
              break;
            }
            if (n >= 0x90 && n <= 0xBF) n = n + 0x30 - 1;
            break;
          }
        case 0xD1: {
            n = source[i]; i++;
            if (n == 0x91) {
              n = 0xB8;
              break;
            }
            if (n >= 0x80 && n <= 0x8F) n = n + 0x70 - 1;
            break;
          }
      }
    }
    m[0] = n; target = target + String(m);
  }
  return target;
}

void max72xxpTime() {
   
}
/*********************************************************************************************\
   Interface
  \*********************************************************************************************/

bool Xdsp13(byte function)
{
  if (function != 2) {
    //    Serial.print("function ");
    //    Serial.print(function);
  }
  bool result = false;

  if (FUNC_DISPLAY_INIT_DRIVER == function ) {
    max72xxpInitDriver();
  }
  else if (XDSP_13 == Settings.display_model) {
    switch (function) {

      case FUNC_DISPLAY_MODEL:
        Serial.println("!!!M O D E L");
        result = true;
        break;
      case FUNC_DISPLAY_POWER:
        max72xxpOnOff();
        break;
      case FUNC_DISPLAY_DRAW_STRING:
       
                max72xxpDrawStringAt();
        break;
#ifdef USE_DISPLAY_MODES1TO5          //3
      case FUNC_DISPLAY_EVERY_SECOND:
        if (disp_power) {
         
        }
        break;
#endif  // USE_DISPLAY_MODES1TO5
    }
  }
  return result;
}



#endif  // USE_DISPLAY_MAX7279
//
#endif  // USE_DISPLAY
#endif  // USE_SPI
