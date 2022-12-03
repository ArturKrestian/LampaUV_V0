class CzasStart
{
private:
public:
    CzasStart()
    {
    }
    void PlayStart()
    {

        extern CzasPracy czasPracy;
        if (czasPracy.isWork == true)
            return;
        czasPracy.isWork = true;
        mSekkundy = 0;
        sekundy = 0;
        czasPracy.sekundyWorkTmp = 0;
        LampOn();
    }
    void Play()
    {
        //   extern KeyData keyData;
        extern void PrintDisplay(int _data);
        extern CzasPracy czasPracy;

        int sekTmp = czasPracy.sekundyWork - sekundy;
        PrintDisplay(sekTmp);
        if (sekTmp <= 0)
        {
            czasPracy.isWork = false;
            LampOff();
            tone(buzzPin, 2000, 100);
            delay(3000);
            PrintDisplay(czasPracy.sekundyWork);
        }
    }
    void Stop()
    {
        extern void PrintDisplay(int _data);

        czasPracy.isWork = false;
        LampOff();
        tone(buzzPin, 2000, 100);
        delay(3000);
        PrintDisplay(czasPracy.sekundyWork);
    }

    void LampOn(int _value = 255)
    {
        analogWrite(lamp_OutPin, _value);
        if (isLamp2On == true)
            analogWrite(lamp2_OutPin, _value);
    }
    void LampOff()
    {
        analogWrite(lamp_OutPin, 0);
        analogWrite(lamp2_OutPin, 0);
    }
};
