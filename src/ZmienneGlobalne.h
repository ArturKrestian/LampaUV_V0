#include <Arduino.h>
//#include <TM1637Display.h>

volatile int sec = 30;
volatile int miliSec = 0;

const int intCzas = 1000;

int secOld = -1;

bool isLamp2On=false;

bool keyOkPush=false;

class TimeWork
{
private:
public:
    int secWork = 0;
    int secWorkTmp = 0;
    bool isWork = false;
    bool isStepStart=false;

    TimeWork()
    {
    }

    void SetTimeAdd()
    {
        if (secWork < 600)
        {
            secWork++;
        Serial.println(secWork);
        }
    }
    void SetCzasMinus()
    {
        if (secWork > 0)
            secWork--;
    }
};
TimeWork timeWork;