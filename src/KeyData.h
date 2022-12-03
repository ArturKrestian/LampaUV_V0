class KeyData
{
private:
    KeyData_Str keyDataOld;

public:
    KeyData()
    {
    }
    private:
    int KlawiszRead()
    {
        // 0 nieprzyciśnięty
        // 1 btn ok
        // 10 btn up
        //100 btn down
        // kombinacja=suma

        int _klawisz = 0;

        if (digitalRead(btn_OkPin) == false)
            _klawisz = 1;
        if (digitalRead(btn_UpPin) == false)
            _klawisz = _klawisz + 10;
        if (digitalRead(btn_DownPin) == false)
            _klawisz = _klawisz + 100;

        return _klawisz;
    }
    public:
    KeyData_Str KlawiszWynik()
    {
     //   extern int sekundy;
      //  extern int mSekkundy;
        int keyTmp=KlawiszRead();
        if(keyTmp==0&&keyDataOld.key==0)return keyDataOld;
        if(keyTmp!=keyDataOld.key&&keyTmp!=0)
        {
            sekundy=0;
            mSekkundy=0;
            keyDataOld.key=keyTmp;
            keyDataOld.time=-1;
         //   tone(buzzPin, 2000, 100);
            return keyDataOld;
        }
        if(keyTmp==0&&keyDataOld.key!=0)
        {
            KeyData_Str keyDataTmp=keyDataOld;
            keyDataOld.key=0;
            keyDataTmp.time=sekundy;
            keyDataOld.time=-1;
           // tone(buzzPin, 2000, 100);
            return keyDataTmp;
        }
        keyDataOld.time=-2;
        return keyDataOld;
    }
};
