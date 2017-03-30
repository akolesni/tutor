// -----------------------------------------------------------------------
// <copyright file="UCListBox.cs" company="ACTIA I+ME GmbH">
// 2017 by ACTIA I+ME GmbH
// </copyright>
// -----------------------------------------------------------------------
namespace WpfTest.Views
{
  using System.Windows.Controls;

  /// <summary>
  /// Interaction logic for UCListBox.xaml
  /// </summary>
  public partial class UCListBox : UserControl
  {
    public UCListBox()
    {
      this.InitializeComponent();
    }

    private void ButtonBase_OnClick(object sender, System.Windows.RoutedEventArgs e)
    {
      //var v = this.ListBox1.Items;

      foreach (var item in this.ListBox1.Items)
      {
        var v = item;
      }

    }
  }
}
