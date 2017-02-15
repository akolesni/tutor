// -----------------------------------------------------------------------
// <copyright file="ValidationView.cs" company="ACTIA I+ME GmbH">
// 2017 by ACTIA I+ME GmbH
// </copyright>
// -----------------------------------------------------------------------
namespace WpfTest.Views
{
  using System.Windows.Controls;

  /// <summary>
  /// Interaction logic for ValidationView.xaml
  /// </summary>
  public partial class ValidationView : UserControl
  {
    public ValidationView()
    {
      this.Cost = "Test";
      this.InitializeComponent();
      this.DataContext = this;
    }

    public string Cost { get; set; }
  }
}
