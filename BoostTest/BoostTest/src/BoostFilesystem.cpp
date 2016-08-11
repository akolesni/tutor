#include <iostream>
#include <cassert>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/fstream.hpp>
#include "BoostFilesystem.h"



BoostFilesystem::BoostFilesystem(void)
{
}


BoostFilesystem::~BoostFilesystem(void)
{
}

void BoostFilesystem::Do()
{
  //this->PathTest();
  //this->StatusTest();
  //this->ManipTest();
  //this->IteratorTest();
  this->Dateistreams();
  //auto s =  myPath02.string();
}

void BoostFilesystem::PathTest()
{
  boost::filesystem::path myPath01("c:\\Users\\AKO\\Desktop\\temp.txt");
  //has_root_name()
  //has_root_directory()
  //has_root_path()
  //has_relative_path()
  //has_parent_path()
  //has_filename()
  assert(std::string("c:")                                == myPath01.root_name().string());
  assert(std::string("\\")                                == myPath01.root_directory().string());
  assert(std::string("c:\\")                              == myPath01.root_path().string());
  assert(std::string("Users\\AKO\\Desktop\\temp.txt")     == myPath01.relative_path().string());
  assert(std::string("c:\\Users\\AKO\\Desktop")           == myPath01.parent_path().string());
  assert(std::string("temp.txt")                          == myPath01.filename().string());
  assert(std::string("temp")                              == myPath01.stem().string());
  assert(std::string(".txt")                              == myPath01.extension().string());
  myPath01.replace_extension(".cpp");
  assert(std::string("c:\\Users\\AKO\\Desktop\\temp.cpp") == myPath01.string());
  myPath01.remove_filename();
  assert(std::string("c:\\Users\\AKO\\Desktop")           == myPath01.string());

  for(auto i = myPath01.begin(); i != myPath01.end(); ++i)
  {
     std::cout << *i << "-";
  }
  // ------------------------------------------------------
  boost::filesystem::path myPath02("AKO/Desktop");
  myPath02 /= "N";
  assert(std::string("AKO/Desktop\\N") == myPath02.string());
  boost::filesystem::path prefPath = myPath02.make_preferred();
  assert(std::string("AKO\\Desktop\\N") == myPath02.string());
  assert(std::string("AKO\\Desktop\\N") == prefPath.string());
}

void BoostFilesystem::StatusTest()
{
  boost::filesystem::path myPath01("c:\\Users\\AKO\\Desktop\\temp.txt");
  boost::filesystem::path myPath02("c:\\Users\\AKO\\Desktop\\temp1.txt");
  try
  {
    boost::filesystem::file_status myPath01Status = status(myPath01);
    assert(boost::filesystem::exists(myPath01Status));
    assert(!boost::filesystem::is_directory(myPath01Status));
    assert(boost::filesystem::is_regular_file(myPath01Status));
    assert(!boost::filesystem::is_symlink(myPath01Status));

    boost::filesystem::file_status myPath02Status = status(myPath02);
    assert(!boost::filesystem::exists(myPath02Status));
    boost::uintmax_t filesize = boost::filesystem::file_size(myPath02);
  }
  catch (boost::filesystem::filesystem_error &e)
  {
    std::cerr << e.what() << '\n';
    std::cout << e.path1() << '\n';
    std::cout << e.path2() << '\n';
  }

  boost::system::error_code ec;
  boost::uintmax_t filesize = boost::filesystem::file_size(myPath01, ec);
  if (!ec)
    std::cout << filesize << '\n';
  else
    std::cout << ec << '\n';

  std::time_t t = boost::filesystem::last_write_time(myPath01);


  std::cout << std::ctime(&t) << '\n';
  // 
  boost::filesystem::path p("C:\\");
  try
  {
    boost::filesystem::space_info s = space(p);
    std::cout <<  "space-------------------\n";
    std::cout << "capacity :" << s.capacity << '\n';
    std::cout << "free :" <<s.free << '\n';
    std::cout << "available :" <<s.available << '\n';
  }
  catch (boost::filesystem::filesystem_error &e)
  {
    std::cerr << e.what() << '\n';
  }
}

void BoostFilesystem::ManipTest()
{
  boost::filesystem::path p("C:\\Test");
  try
  {
    if (create_directory(p))
    {
      rename(p, "C:\\Test2");
      boost::filesystem::remove("C:\\Test2");
    }
  }
  catch (boost::filesystem::filesystem_error& e)
  {
    std::cerr << e.what() << '\n';
  }
  //
  boost::filesystem::path p1("C:\\Test\\test\\test11\\jhdjhd");
  try
  {
    if (create_directories(p1))
    {
      rename(p1, "C:\\Test2");
      boost::filesystem::remove("C:\\Test2");
     // bool r = boost::filesystem::remove("C:\\Test");
      boost::filesystem::remove_all("C:\\Test");
    }
  }
  catch (boost::filesystem::filesystem_error& e)
  {
    std::cerr << e.what() << '\n';
  }
  // -----------------
  try
  {
    std::cout << boost::filesystem::absolute("photo.jpg") << '\n';
  }
  catch (boost::filesystem::filesystem_error &e)
  {
    std::cerr << e.what() << '\n';
  }
  //--
  try
  {
    std::cout << boost::filesystem::absolute("photo.jpg", "D:\\") << '\n';
  }
  catch (boost::filesystem::filesystem_error &e)
  {
    std::cerr << e.what() << '\n';
  }
  // -----------

  try
  {
    std::cout << boost::filesystem::current_path() << '\n';
    boost::filesystem::current_path("C:\\");
    std::cout << boost::filesystem::current_path() << '\n';
  }
  catch (boost::filesystem::filesystem_error &e)
  {
    std::cerr << e.what() << '\n';
  }

}

void BoostFilesystem::IteratorTest()
{
  boost::filesystem::path p = boost::filesystem::current_path();
  boost::filesystem::directory_iterator it(p);
  boost::filesystem::directory_iterator a;
  while (it != a)
    std::cout << *it++ << '\n';


  //boost::filesystem::recursive_directory_iterator

}

void BoostFilesystem::Dateistreams()
{
  boost::filesystem::path p("test.txt");
  boost::filesystem::ofstream ofs(p);

  //ofs.open(p);

  ofs << "Hello, world!\n";
}