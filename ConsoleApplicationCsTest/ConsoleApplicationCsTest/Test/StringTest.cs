using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplicationCsTest.Test
{
    public class StringTest
    {
      public void Do()
      {
        this.Test1();
      }

      private void Test1()
      {
        string s = "@\x0002@\x02abcd@\x02";

        Console.WriteLine(s);
      }
    }
}
