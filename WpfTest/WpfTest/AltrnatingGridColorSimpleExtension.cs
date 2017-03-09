namespace WpfTest
{
  using System;
  using System.Reflection;
  using System.Windows;
  using System.Windows.Controls;
  using System.Windows.Markup;
  using System.Windows.Media;

  public class AltrnatingGridColorSimpleExtension : MarkupExtension
  {
    public Color ColorEven { get; set; }
    public Color ColorOdd { get; set; }
    public override object ProvideValue(IServiceProvider serviceProvider)
    {
      if (serviceProvider == null) return this;

      IProvideValueTarget service = 
        serviceProvider.GetService(typeof(IProvideValueTarget))as IProvideValueTarget;

      if (service == null) return this;

      Type targetPropertyType = null;
      if (service.TargetProperty is DependencyProperty)
      {
        targetPropertyType = ((DependencyProperty)service.TargetProperty).PropertyType;
      }
      else if (service.TargetProperty is PropertyInfo)
      {
        targetPropertyType = ((PropertyInfo)service.TargetProperty).PropertyType;
      }
      else
      {
        return this;
      }

      if (!typeof(Brush).IsAssignableFrom(targetPropertyType))
      {
        return null;
      }

      SolidColorBrush brush = new SolidColorBrush(ColorEven);

      if (service.TargetObject is DependencyObject)
      {
        var depObject = (DependencyObject)service.TargetObject;
        var row = (int)depObject.GetValue(Grid.RowProperty);
        if (row % 2 != 0)
        {
          brush.Color = ColorOdd;
        }
      }

      return brush;
    }

    public AltrnatingGridColorSimpleExtension()
    {
    }
  }
}
