namespace ConsoleApplicationCsTest.MEF
{
  using System;
  using System.ComponentModel.Composition;
  using System.ComponentModel.Composition.Hosting;

  using ICar;

  internal class MefTest
  {

    // ComposablePartCatalog kontrolliert das Laden der Komponenten
    // CompositionContainer die Instanzen erzeugt und diese an die entsprechenden Variablen bindet


    [ImportMany(typeof(ICarContract))]
    private ICarContract[] cars = null;
    public void Do()
    {
        var catalog = new DirectoryCatalog(".");

        var container = new CompositionContainer(catalog);
        container.ComposeParts(this);

        foreach (ICarContract contract in this.cars)
        {
          Console.WriteLine(contract.StartEngine("Sebastian"));
        }
    }

  }
}
