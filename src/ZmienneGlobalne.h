#include <Arduino.h>

volatile int sec = 30;
volatile int miliSec = 0;

const int intCzas = 1000;

int secOld = -1;

bool isLamp2On=false;

bool keyOkPush=false;


