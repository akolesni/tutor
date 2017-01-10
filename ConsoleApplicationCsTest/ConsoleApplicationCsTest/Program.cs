using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplicationCsTest
{
  using ConsoleApplicationCsTest.MEF;
  using ConsoleApplicationCsTest.Test;

  internal class Program
  {
    private static void Main(string[] args)
    {
      //Environment.CommandLine.
      //MefTest mefTest = new MefTest();
      //mefTest.Do();
      StringTest stringTest = new StringTest();
      stringTest.Do();

      //--------------------
      Console.ReadLine();
    }
  }
}
