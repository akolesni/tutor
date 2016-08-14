using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplicationCsTest
{
  using ConsoleApplicationCsTest.MEF;

  internal class Program
  {
    private static void Main(string[] args)
    {
      //Environment.CommandLine.
      MefTest mefTest = new MefTest();
      mefTest.Do();




      //--------------------
      Console.ReadLine();
    }
  }
}
