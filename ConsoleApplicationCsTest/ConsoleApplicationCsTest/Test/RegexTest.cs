namespace ConsoleApplicationCsTest.Test
{
  using System;
  using System.Text.RegularExpressions;

  internal class RegexTest
  {
    internal void Do()
    {
      this.IsMatchTest();
    }

    private void IsMatchTest()
    {
      // IP Adress
      Regex rgx = new Regex(@"^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$");
      string ip1 = null; 
      string ip2 = "";
      string ip3 = "  ";
      string ip4 = "0.0.0.0";
      string ip5 = ".127.23.12.0";
      string ip6 = "1.23.45.67";

      // Console.WriteLine(@"{ip1} " + (rgx.IsMatch(ip1) ? "ip" :"not ip")); ArgumentNullException

      Console.WriteLine(@"{ip2} " + (rgx.IsMatch(ip2) ? "ip" : "not ip"));
      Console.WriteLine(@"{ip3} " + (rgx.IsMatch(ip3) ? "ip" : "not ip"));
      Console.WriteLine(@"{ip4} " + (rgx.IsMatch(ip4) ? "ip" : "not ip"));
      Console.WriteLine(@"{ip5} " + (rgx.IsMatch(ip5) ? "ip" : "not ip"));
      Console.WriteLine(@"{ip6} " + (rgx.IsMatch(ip6) ? "ip" : "not ip"));
    }
  }
}
