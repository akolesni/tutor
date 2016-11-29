#include "..\include\BoostAsioTest.h"
#include <iostream>

#include "boost\asio.hpp"


using namespace boost::asio;

BoostAsioTest::BoostAsioTest()
{
}


BoostAsioTest::~BoostAsioTest()
{
}



io_service service;
ip::udp::socket sock(service);
boost::asio::ip::udp::endpoint sender_ep;
char buff[512];



void on_read(const boost::system::error_code & err, std::size_t read_bytes)
{
	std::cout << "read " << read_bytes << std::endl;
	sock.async_receive_from(buffer(buff), sender_ep, on_read);

	std::for_each(&buff[0], &buff[read_bytes], [&](size_t b)
	{
		std::cout << (unsigned int)b << "\n";
	});

}


void BoostAsioTest::Do()
{
	ip::udp::endpoint ep(ip::address::from_string("169.254.255.100"), 13400);

	sock.open(ep.protocol());
	sock.set_option(boost::asio::ip::udp::socket::reuse_address(true));
	sock.bind(ep);
	sock.async_receive_from(buffer(buff, 512), sender_ep, on_read);
	service.run();
}
