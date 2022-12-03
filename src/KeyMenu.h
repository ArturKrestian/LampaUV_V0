#include <Arduino.h>
class KeyMenu
{
private:
    KeyData_Str keyDataOld;
    int secOld = 0;

public:
    KeyMenu()
    {
    }
    void Menu()
    {
        extern KeyData keyData;
        extern void PrintDisplay(int _data);
        extern TimeWork timeWork;
        extern TimeStart timeStart;
        //   extern int sekundy;

        KeyData_Str keyTmp = keyData.KeyValue();

        if (keyDataOld.key != keyTmp.key)
            timeWork.isStepStart = false;
        keyDataOld = keyTmp;

        switch (keyTmp.key)
        {
        case 0:
        {
            keyOkPush=false;
             keyTmp = keyData.KeyValue();

            break;
        }
        case 1: // ok
        {
            if(keyOkPush==true)break;
            //  Serial.println(">>OK");
            if (timeWork.isWork == true && keyTmp.time > -1)
            {
                timeStart.Stop();
                // Serial.println("keyTmp.key" + (String)keyTmp.key);
                delay(500);
                keyTmp = keyData.KeyValue();

                break;
            }
            if(keyTmp.time<0&&sec>0&&keyOkPush==false&&timeWork.isWork == false)
            {
                tone(buzzPin, 4000, 100);
                keyOkPush=true;
                isLamp2On=!isLamp2On;
                 PrintDisplay(timeWork.secWork);
            }
            if (keyTmp.time < 0)
                break;
            if (keyTmp.time < 1&&timeWork.isWork == false)
            {

                EpromPut();
                timeStart.PlayStart();
                delay(500);

                keyTmp = keyData.KeyValue();
            }
                Serial.println("time=" + String(keyTmp.time));
            break;
        }
        case 10: // up
        {
            if (timeWork.isWork == true)
            {
                break;
            }
            Serial.println(">>up");
            if (keyTmp.time == -2)
            {
                if (timeWork.isStepStart == false)
                {
                    timeWork.isStepStart = true;
                    secOld = sec;
                }
                else
                {
                    if ((sec - secOld) < 1)
                        return;
                }
                timeWork.SetTimeAdd();
                delay(100);
            }
            PrintDisplay(timeWork.secWork);
            break;
        }
        case 100: // down
        {
            if (timeWork.isWork == true)
            {
                return;
            }
            Serial.println(">>down");
            if (keyTmp.time == -2)
            {
                if (timeWork.isStepStart == false)
                {
                    timeWork.isStepStart = true;
                    secOld = sec;
                }
                else
                {
                    if ((sec - secOld) < 1)
                        return;
                }
                timeWork.SetCzasMinus();
                delay(100);
            }
            PrintDisplay(timeWork.secWork);
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
        EEPROM.put(0, timeWork.secWork);
    }
};
