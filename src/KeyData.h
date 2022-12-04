class KeyData
{
private:
    KeyData_Str keyDataOld;

public:
    KeyData()
    {
    }

private:
    int KeyRead()
    {
        // 0 nieprzyciśnięty
        // 1 btn ok
        // 10 btn up
        // 100 btn down
        // kombinacja=suma

        int _key = 0;

        if (digitalRead(btn_OkPin) == false)
            _key = 1;
        if (digitalRead(btn_UpPin) == false)
            _key = _key + 10;
        if (digitalRead(btn_DownPin) == false)
            _key = _key + 100;

        return _key;
    }

public:
    KeyData_Str KeyValue()
    {
        int keyTmp = KeyRead();
        if (keyTmp == 0 && keyDataOld.key == 0)
            return keyDataOld;
        if (keyTmp != keyDataOld.key && keyTmp != 0)
        {
            sec = 0;
            miliSec = 0;
            keyDataOld.key = keyTmp;
            keyDataOld.time = -1;
            return keyDataOld;
        }
        if (keyTmp == 0 && keyDataOld.key != 0)
        {
            KeyData_Str keyDataTmp = keyDataOld;
            keyDataOld.key = keyTmp;
            keyDataOld.time = -1;
            keyDataTmp.time = sec;
            return keyDataTmp;
        }
        keyDataOld.time = -2;
        return keyDataOld;
    }
};
