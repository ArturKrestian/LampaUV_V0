#include <Arduino.h>
#include <TM1637Display.h>
#include <TimerOne.h>
#include "EEPROM.h"
#include <defPin.h>
#include <ZmienneGlobalne.h>
#include <Struktury.h>
#include <KeyData.h>
#include <CzasStart.h>
#include <KeyMenu.h>

#include <Przerwanie.h>

TM1637Display display(disp_ClkPin, disp_DioPin);
KeyData keyData;
CzasStart czasStart;
KeyMenu keyMenu;

void PrintDisplay(int _data)
{
  uint8_t lamp1[] = {
      SEG_D};
  uint8_t lamp2[] = {
      SEG_A | SEG_D

  };
  // display.clear();
  // tone(buzzPin, 2000, 100);
  display.showNumberDec(_data, false, 3, 1);
  if (isLamp2On == false)
  {
    display.setSegments(lamp1, 1, 0);
  }
  else
  {
    display.setSegments(lamp2, 1, 0);
  }
}

void EpromGet()
{
  EEPROM.get(0, czasPracy.sekundyWork);
}

void setup()
{
  pinMode(disp_ClkPin, OUTPUT);
  pinMode(disp_DioPin, OUTPUT);
  pinMode(btn_UpPin, INPUT);
  pinMode(btn_DownPin, INPUT);
  pinMode(btn_OkPin, INPUT);
  pinMode(lamp_OutPin, OUTPUT);
  pinMode(lamp2_OutPin, OUTPUT);

  display.clear();
  display.setBrightness(7);
  Serial.begin(9600);
  Serial.println("start");

  Timer1.initialize(intCzas);
  Timer1.attachInterrupt(przerwanie);
  tone(buzzPin, 2000, 100);
  EpromGet();
  PrintDisplay(czasPracy.sekundyWork);
  //  digitalWrite(lamp_OutPin,true);
  // digitalWrite(lamp2_OutPin,true);
  // PrintDisplay(10);
}

void loop()
{
  // Serial.println(czasPracy.sekundyWork);
  keyMenu.Menu();
  if (czasPracy.isWork == true)
    czasStart.Play();
  // if (sekundyOld != sekundy)
  //{
  //  KeyData_Str keyDataTmp=keyData.KlawiszWynik();
  // if(keyDataTmp.time!=-1)
  // PrintDisplay(keyDataTmp.time);
  // sekundyOld = sekundy;
  // }
}
