namespace ConsoleApplicationCsTest.Test
{
  using System;
  using System.Diagnostics;
  using System.IO;
  using System.IO.Compression;
  using System.Reflection;
  using System.Security.Cryptography;
  using System.Xml.Serialization;

  using SevenZip;

  public class PurchaseOrder
  {
    public Address MyAddress;
  }
  public class Address
  {
    public string FirstName;
  }

  public class StreamTest
  {
    public void Do()
    {
      this.TestZip();
      //this.Test7Zip();
    }

    private void TestZip()
    {
      Address address = new Address();
      address.FirstName = "Ivanov";
      PurchaseOrder purchaseOrder = new PurchaseOrder();
      purchaseOrder.MyAddress = address;

      XmlSerializer formatter = new XmlSerializer(typeof(PurchaseOrder));

      string codeBase = Assembly.GetExecutingAssembly().CodeBase;
      UriBuilder uri = new UriBuilder(codeBase);
      string path = Uri.UnescapeDataString(uri.Path);
      string wd = Path.GetDirectoryName(path);



      using (FileStream fs = new FileStream("test.xml", FileMode.Create))
      {
        formatter.Serialize(fs, purchaseOrder);
      }

      //ProcessStartInfo startInfo = new ProcessStartInfo("zip.exe");
      //startInfo.Arguments = "-j";
      //startInfo.Arguments = "-P";
      //startInfo.Arguments = "Swahadhoup";
      //startInfo.Arguments = "test.zip";
      //startInfo.Arguments = "test.xml";

      //Process.Start(startInfo);



      //Process.Start(wd + "\\zip.exe -j -P Swahadhoup test.zip test.xml");
      Process.Start(wd + "\\zip.exe","-j -P Swahadhoup test.zip test.xml");
    }

    /*
     
                   ProcessStartInfo startInfo = new ProcessStartInfo("IExplore.exe");
            startInfo.WindowStyle = ProcessWindowStyle.Minimized;

            Process.Start(startInfo);

            startInfo.Arguments = "www.northwindtraders.com";

            Process.Start(startInfo);
       */


    private void Test7Zip()
    {
      //SevenZipBase.SetLibraryPath(Path.Combine(
      //        Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location) ?? Environment.CurrentDirectory,
      //        "7za.dll"));

      //SevenZipCompressor compressor = new SevenZipCompressor();

      //compressor.Compressing += Compressor_Compressing;
      //compressor.FileCompressionStarted += Compressor_FileCompressionStarted;
      //compressor.CompressionFinished += Compressor_CompressionFinished;

      //string password = @"whatever";
      //string destinationFile = @"C:\Temp\whatever.zip";
      //string[] sourceFiles = Directory.GetFiles(@"C:\Temp\YourFiles\");

      //if (String.IsNullOrWhiteSpace(password))
      //{
      //  compressor.CompressFiles(destinationFile, sourceFiles);
      //}
      //else
      //{
      //  //optional
      //  compressor.EncryptHeaders = true;
      //  compressor.CompressFilesEncrypted(destinationFile, password, sourceFiles);
      //}
    }

    //private void TestZip()
    //{
    //  Address address = new Address();
    //  address.FirstName = "Ivanov";
    //  PurchaseOrder purchaseOrder = new PurchaseOrder();
    //  purchaseOrder.MyAddress = address;

    //  XmlSerializer formatter = new XmlSerializer(typeof(PurchaseOrder));

    //  //
    //  byte[] key = new byte[]
    //                 {
    //                   (byte)'S', (byte)'w', (byte)'a', (byte)'h', (byte)'a', (byte)'d', (byte)'h', (byte)'o', (byte)'u',
    //                   (byte)'p'
    //                 };


    //  //using (FileStream fs = new FileStream("test.zip", FileMode.Create))
    //  using (FileStream fs = File.Create("test.xml.zip"))
    //  {
    //    using (GZipStream compressionStream = new GZipStream(fs, CompressionMode.Compress))
    //    {

    //      using (AesCryptoServiceProvider aesAlg = new AesCryptoServiceProvider())
    //      {
    //        aesAlg.KeySize = key.Length;
    //        aesAlg.Key = key;
    //        aesAlg.IV = new byte[] {0,0,0,0};
    //        // Create a decrytor to perform the stream transform. 
    //        ICryptoTransform encryptor = aesAlg.CreateEncryptor(
    //                                        aesAlg.Key, aesAlg.IV);
    //        // Create the streams used for encryption. 
    //        using (MemoryStream msEncrypt = new MemoryStream())
    //        {
    //          using (CryptoStream csEncrypt = new CryptoStream(msEncrypt,
    //                                  encryptor, CryptoStreamMode.Write))
    //          {
    //            formatter.Serialize(csEncrypt, purchaseOrder);
    //            //using (StreamWriter swEncrypt = new StreamWriter(csEncrypt))
    //            //{
    //            //  // Write all data to the stream. 
    //            //  swEncrypt.Write(plainText);
    //            //}
    //            //encrypted = msEncrypt.ToArray();
    //          }
    //        }
    //      }





    //      //formatter.Serialize(compressionStream, purchaseOrder);

    //    }



    //  }

    //}

  }
}
