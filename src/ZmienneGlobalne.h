#include <Arduino.h>
//#include <TM1637Display.h>

volatile int sekundy = 30;
volatile int mSekkundy = 0;

const int intCzas = 1000;

int sekundyOld = -1;

bool isLamp2On=false;

bool keyOkPush=false;

class CzasPracy
{
private:
public:
    int sekundyWork = 0;
    int sekundyWorkTmp = 0;
    bool isWork = false;
    bool isStepStart=false;

    CzasPracy()
    {
    }

    void SetCzasPlus()
    {
        if (sekundyWork < 600)
        {
            sekundyWork++;
        Serial.println(sekundyWork);
        }
    }
    void SetCzasMinus()
    {
        if (sekundyWork > 0)
            sekundyWork--;
    }
};
CzasPracy czasPracy;