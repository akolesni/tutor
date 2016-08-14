using System;
using System.ComponentModel.Composition;

namespace CarBMW
{
  [Export(typeof(ICar.ICarContract))]
  public class BMW : ICar.ICarContract
  {
    public string StartEngine(string name)
    {
      return String.Format("{0} starts the BMW.", name);
    }
  }
}
