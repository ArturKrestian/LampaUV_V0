struct KeyData_Str
{
    int key;
    int time;
};
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
     //   Serial.println(secWork);
        }
    }
    void SetCzasMinus()
    {
        if (secWork > 0)
            secWork--;
    }
};
