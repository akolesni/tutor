#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "BoostProgramOptions.h"
#include "boost/program_options.hpp"

namespace po = boost::program_options;

BoostProgramOptions::BoostProgramOptions()
{
}


BoostProgramOptions::~BoostProgramOptions()
{
}

void on_age(int age)
{
	std::cout << "On age: " << age << '\n';
}

void to_cout(const std::vector<std::string> &v)
{

	//for each (auto var in v)
	//{
	//	std::wcout << var;
	//}

	std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>{
		std::cout, "\n"});
}

void BoostProgramOptions::Do(int argc, char* argv[])
{
	int age;
	try
	{
		// 1.definieren Kommandozeilenparameter.
		po::options_description desc{ "Options" };
		// desc.add(option_description)

		desc.add_options()
		("help,h", "Help screen")                                                                         // Schalter
		("path", po::value<std::string>()->default_value("PDUAPI_I+ME_ACTIA_XS.dll"), "PDU API dll path") // Name/Wert-Paar
		("vci", po::value<std::string>()->default_value("Xentry Connect"), "VCI type")                    // Name/Wert-Paar
		//("pi", po::value<float>()->default_value(3.14f), "Pi")
		//("age", po::value<int>()->notifier(on_age)->default_value(50), "Age");
		
		// Es reicht, wenn --pi angegeben wird, ohne dass hinter dem Parameternamen ein Wert gesetzt wird. Dann ist Pi mit 3,14 definiert.
		("pi", po::value<float>()->implicit_value(3.14f), "Pi")
        ("age", po::value<int>(&age), "Age")

		// multitoken 123 2672 283
		//
        ("phone", po::value<std::vector<std::string>>()->multitoken()->zero_tokens()->composing(), "Phone")
        
		("unreg", "Unrecognized options");

		po::command_line_parser parser{ argc, argv };
		//po::wcommand_line_parser parser{ argc, argv };
		

		parser.options(desc).allow_unregistered().style(
			po::command_line_style::default_style |
			po::command_line_style::allow_slash_for_short);

		po::parsed_options parsed_options = parser.run();
		//po::wparsed_options parsed_options = parser.run();
		

		po::variables_map vm;
		store(parsed_options, vm);
		notify(vm);



		
		//po::variables_map vm; // map ->std::map<std::string, boost::program_options::variable_value>

		//// 2.Parser, -> parse_command_line
		//// 3. Save in map -> store(...)
		//store(parse_command_line(argc, argv, desc), vm);

		//notify(vm);

		// 3.
		//if (vm.count("help"))
		//{
		//	std::cout << desc << '\n';
		//	//return 0;
		//}


		if (vm.count("help"))
			std::cout << desc << '\n';
		else if (vm.count("age"))
			std::cout << "Age: " << age << '\n';
		else if (vm.count("phone"))
			to_cout(vm["phone"].as<std::vector<std::string>>());
		else if (vm.count("unreg"))
			to_cout(po::collect_unrecognized(parsed_options.options, po::exclude_positional));
		else if (vm.count("pi"))
			std::cout << "Pi: " << vm["pi"].as<float>() << '\n';



		//vm["path"].value()

		std::string strDllPath = vm["path"].as<std::string>();

		std::cout << "dll path :" << strDllPath << '\n';


	}
	catch (const po::error &ex)
	{
		std::cerr << ex.what() << '\n';
	}
	catch (std::string& _strExeption)
	{
		std::cout << _strExeption;
		//return 1;
	}
	catch (...)
	{
		std::cout << "Error";
		//return 2;
	}
}
