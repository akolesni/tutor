using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplicationCsTest.Test
{
  public class DateTimeTest
  {
    /*
     https://msdn.microsoft.com/de-de/library/8kb3ddd4(v=vs.110).aspx
       */
    public void Do()
    {
      //CreateDateTime();
      PrintDateTime();
    }

    private void PrintDateTime()
    {
      DateTime dateTime = DateTime.Now;
      Console.WriteLine("yyyyMMddHHmmss - " + dateTime.ToString("yyyyMMddHHmmss"));
      Console.WriteLine("D - " + dateTime.ToString("D"));
      Console.WriteLine("d - " + dateTime.ToString("d"));

      Console.WriteLine("yyyy-MM-ddHH:mm:ss - " + dateTime.ToString("yyyy-MM-ddTHH:mm:ss"), System.Globalization.CultureInfo.InvariantCulture);
    }

    private void CreateDateTime()
    {
      DateTime dateTime1 = DateTime.ParseExact(
        "2017-01-18T16:59:18",
        "yyyy-MM-ddTHH:mm:ss",
        System.Globalization.CultureInfo.InvariantCulture);
    }
  }
}
