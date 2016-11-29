using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WpfTest
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

    private async void button_Click(object sender, RoutedEventArgs e)
    {
      button.IsEnabled = false;

      Task<string> slowTask = Task<string>.Factory.StartNew(() => SlowDude());

      //textBoxResults.Text += "Doing other things while waiting for that slow dude...\r\n";

      await slowTask;

      textBox.Text += slowTask.Result.ToString();

      button.IsEnabled = true;
    }
    private string SlowDude()
    {
      Thread.Sleep(5000);
      return "Ta-dam! Here I am!\r\n";
    }
  }
}
