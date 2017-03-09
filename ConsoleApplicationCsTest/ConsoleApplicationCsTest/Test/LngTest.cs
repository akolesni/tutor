namespace ConsoleApplicationCsTest.Test
{
  using System;

  public class LngTest
  {
    public void Do()
    {
      this.TestInc();
    }

    private void TestInc()
    {
      int a = 1;
      Console.WriteLine($"a++ = {a++}"); // 1
      Console.WriteLine($"++a = {++a}"); // 3

      // --------------------------------------
      a = 1;
      int b;
      b = ++a;
      Console.WriteLine($"b = ++a = {b}"); // 2
      a = 1;
      b = 0;
      b = a++;
      Console.WriteLine($"b = a++ = {b}"); // 1
    }
  }
}
