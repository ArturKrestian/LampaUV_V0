#include <Arduino.h>
class KeyMenu
{
private:
    KeyData_Str keyDataOld;
    int sekundyOld = 0;

public:
    KeyMenu()
    {
    }
    void Menu()
    {
        extern KeyData keyData;
        extern void PrintDisplay(int _data);
        extern CzasPracy czasPracy;
        extern CzasStart czasStart;
        //   extern int sekundy;

        KeyData_Str keyTmp = keyData.KlawiszWynik();

        if (keyDataOld.key != keyTmp.key)
            czasPracy.isStepStart = false;
        keyDataOld = keyTmp;

        switch (keyTmp.key)
        {
        case 0:
        {
            keyOkPush=false;
             keyTmp = keyData.KlawiszWynik();

            break;
        }
        case 1: // ok
        {
            if(keyOkPush==true)break;
            //  Serial.println(">>OK");
            if (czasPracy.isWork == true && keyTmp.time > -1)
            {
                czasStart.Stop();
                // Serial.println("keyTmp.key" + (String)keyTmp.key);
                delay(500);
                keyTmp = keyData.KlawiszWynik();

                break;
            }
            if(keyTmp.time<0&&sekundy>0&&keyOkPush==false&&czasPracy.isWork == false)
            {
                tone(buzzPin, 4000, 100);
                keyOkPush=true;
                isLamp2On=!isLamp2On;
                 PrintDisplay(czasPracy.sekundyWork);
            }
            if (keyTmp.time < 0)
                break;
            if (keyTmp.time < 1&&czasPracy.isWork == false)
            {

                EpromPut();
                czasStart.PlayStart();
                delay(500);

                keyTmp = keyData.KlawiszWynik();
            }
                Serial.println("time=" + String(keyTmp.time));
            break;
        }
        case 10: // up
        {
            if (czasPracy.isWork == true)
            {
                break;
            }
            Serial.println(">>up");
            if (keyTmp.time == -2)
            {
                if (czasPracy.isStepStart == false)
                {
                    czasPracy.isStepStart = true;
                    sekundyOld = sekundy;
                }
                else
                {
                    if ((sekundy - sekundyOld) < 1)
                        return;
                }
                czasPracy.SetCzasPlus();
                delay(100);
            }
            PrintDisplay(czasPracy.sekundyWork);
            break;
        }
        case 100: // down
        {
            if (czasPracy.isWork == true)
            {
                return;
            }
            Serial.println(">>down");
            if (keyTmp.time == -2)
            {
                if (czasPracy.isStepStart == false)
                {
                    czasPracy.isStepStart = true;
                    sekundyOld = sekundy;
                }
                else
                {
                    if ((sekundy - sekundyOld) < 1)
                        return;
                }
                czasPracy.SetCzasMinus();
                delay(100);
            }
            PrintDisplay(czasPracy.sekundyWork);
            break;
        }
        case 101:
        {
            PrintDisplay(101);
            break;
        }
        case 110:
        {
            PrintDisplay(110);
            break;
        }
        case 111:
        {
            PrintDisplay(111);
            break;
        }
        case 11:
        {
            PrintDisplay(11);

            break;
        }
        default:
        {
            PrintDisplay(keyTmp.key);
            break;
        }
        }
    }
    void EpromPut()
    {
        EEPROM.put(0, czasPracy.sekundyWork);
    }
};
