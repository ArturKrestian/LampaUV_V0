class TimeStart
{
private:
public:
    TimeStart()
    {
    }
    void PlayStart()
    {

        extern TimeWork timeWork;
        if (timeWork.isWork == true)
            return;
        timeWork.isWork = true;
        miliSec = 0;
        sec = 0;
        timeWork.secWorkTmp = 0;
        LampOn();
    }
    void Play()
    {
        //   extern KeyData keyData;
        extern void PrintDisplay(int _data);
        extern TimeWork timeWork;

        int sekTmp = timeWork.secWork - sec;
        PrintDisplay(sekTmp);
        if (sekTmp <= 0)
        {
            timeWork.isWork = false;
            LampOff();
            tone(buzzPin, 2000, 100);
            delay(3000);
            PrintDisplay(timeWork.secWork);
        }
    }
    void Stop()
    {
        extern void PrintDisplay(int _data);
        extern TimeWork timeWork;

        timeWork.isWork = false;
        LampOff();
        tone(buzzPin, 2000, 100);
        delay(3000);
        PrintDisplay(timeWork.secWork);
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
