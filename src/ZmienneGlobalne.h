#include <Arduino.h>

volatile int sec = 0;
volatile int miliSec = 0;

const int irqTime = 1000;

int secOld = -1;

bool isLamp2On=false;

bool keyOkPush=false;


