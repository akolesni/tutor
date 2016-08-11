#pragma once
class BoostFilesystem
{
public:
  BoostFilesystem(void);
  virtual ~BoostFilesystem(void);
  void Do();
  void PathTest();
  void StatusTest();
  void ManipTest();
  void IteratorTest();
  void Dateistreams();
};

