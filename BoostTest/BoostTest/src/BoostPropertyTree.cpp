#include "BoostPropertyTree.h"
#include <boost/property_tree/ptree.hpp>
#include <iostream>

using boost::property_tree::ptree;

BoostPropertyTree::BoostPropertyTree()
{
}


BoostPropertyTree::~BoostPropertyTree()
{
}

void BoostPropertyTree::Do()
{
	//this->Test1();
	//this->Test2();
	this->Test3();
}

void BoostPropertyTree::Test1()
{
	ptree pt;
	pt.put("C:.Windows.System", "20 files");

	ptree &c = pt.get_child("C:");
	ptree &windows = c.get_child("Windows");
	ptree &system = windows.get_child("System");
	std::cout << system.get_value<std::string>() << '\n';
}

void BoostPropertyTree::Test2()
{
	typedef boost::property_tree::basic_ptree<std::string, int> ptree;
	ptree pt;
	pt.put(ptree::path_type{ "C:\\Windows\\System", '\\' }, 20);
	pt.put(ptree::path_type{ "C:\\Windows\\Cursors", '\\' }, 50);

	ptree &windows = pt.get_child(ptree::path_type{ "C:\\Windows", '\\' });
	int files = 0;
	for (const std::pair<std::string, ptree> &p : windows)
		files += p.second.get_value<int>();
	std::cout << files << '\n';
}

#include <boost/property_tree/ini_parser.hpp>
void BoostPropertyTree::Test3()
{
	boost::property_tree::ptree pt;
	boost::property_tree::ini_parser::read_ini("config.ini", pt);
	std::cout << pt.get<std::string>("Section1.Value1") << std::endl;
	std::cout << pt.get<std::string>("Section1.Value2") << std::endl;
	//-------
	pt.put("Section1.Value1", "new");

	boost::property_tree::ini_parser::write_ini("config.ini", pt);
}
