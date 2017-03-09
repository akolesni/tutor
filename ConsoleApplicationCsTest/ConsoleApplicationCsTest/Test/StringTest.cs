using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplicationCsTest.Test
{
  public class ByteByByteFormatter : IFormatProvider, ICustomFormatter
  {
    public object GetFormat(Type formatType)
    {
      if (formatType == typeof(ICustomFormatter))
        return this;
      else
        return null;
    }

    public string Format(string format, object arg,
                           IFormatProvider formatProvider)
    {
      if (!formatProvider.Equals(this)) return null;

      // Handle only hexadecimal format string.
      if (!format.StartsWith("X")) return null;

      byte[] bytes;
      string output = null;

      // Handle only integral types.
      if (arg is Byte)
        bytes = BitConverter.GetBytes((Byte)arg);
      else if (arg is Int16)
        bytes = BitConverter.GetBytes((Int16)arg);
      else if (arg is Int32)
        bytes = BitConverter.GetBytes((Int32)arg);
      else if (arg is Int64)
        bytes = BitConverter.GetBytes((Int64)arg);
      else if (arg is SByte)
        bytes = BitConverter.GetBytes((SByte)arg);
      else if (arg is UInt16)
        bytes = BitConverter.GetBytes((UInt16)arg);
      else if (arg is UInt32)
        bytes = BitConverter.GetBytes((UInt32)arg);
      else if (arg is UInt64)
        bytes = BitConverter.GetBytes((UInt64)arg);
      else
        return null;

      for (int ctr = bytes.Length - 1; ctr >= 0; ctr--)
        output += String.Format("{0:X2} ", bytes[ctr]);

      return output.Trim();
    }
  }

  public class StringTest
  {
    public void Do()
    {
      //this.Test1();
      this.HexString();
    }

    private void Test1()
    {
      string s = "@\x0002@\x02abcd@\x02";

      Console.WriteLine(s);
    }

    private void HexString()
    {
      long value = 3210662321;
      byte value1 = 214;
      byte value2 = 19;

      Console.WriteLine(String.Format(new ByteByByteFormatter(), "{0:X}", value));

      //Console.WriteLine(String.Format(new ByteByByteFormatter(), "{0:X} And {1:X} = {2:X} ({2:000})",
      //                                value1, value2, value1 & value2));
      Console.WriteLine(String.Format(new ByteByByteFormatter(), "{0,10:N0}", value));

      var result = Convert.ToString(value1, 2);
    }

  }
}
