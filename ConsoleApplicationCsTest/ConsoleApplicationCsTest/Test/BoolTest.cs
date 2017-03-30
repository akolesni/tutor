// -----------------------------------------------------------------------
// <copyright file="BoolTest.cs" company="ACTIA I+ME GmbH">
// 2017 by ACTIA I+ME GmbH
// </copyright>
// -----------------------------------------------------------------------
namespace ConsoleApplicationCsTest.Test
{
  using System;

  public class BoolTest
  {
    public void Do()
    {
      this.Test1();
    }

    private void Test1()
    {
      // 0F FF FF
      // 1048575
      uint max = 20; // 14
      //byte maxValue = (byte)Math.Pow(2, max) - 1;

      uint maxValueN = ~max;




      //byte value1 = 0xFFFFFFFFFF0F0F0F;




      //string.Format("{0:X2} ", bytes[ctr]);

      //Console.WriteLine(maxValue.ToString("X"));
    }
  }
}
