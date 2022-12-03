void Irq()
{
  //  if(sekundy<=0)return;
    miliSec++;
    if (miliSec > 1000)
    {
        miliSec = 0;
        sec++;
    }
}