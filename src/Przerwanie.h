void przerwanie()
{
  //  if(sekundy<=0)return;
    mSekkundy++;
    if (mSekkundy > 1000)
    {
        mSekkundy = 0;
        sekundy++;
    }
}