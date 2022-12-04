void Irq()
{
  //  if(sekundy<=0)return;
    miliSec++;
    if (miliSec > 999)
    {
        miliSec = 0;
        sec++;
    }
}