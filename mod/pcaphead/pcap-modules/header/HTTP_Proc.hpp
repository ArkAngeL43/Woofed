#include "/usr/local/include/pcapplusplus/SystemUtils.h"
#include "/usr/local/include/pcapplusplus/Packet.h"
#include "/usr/local/include/pcapplusplus/EthLayer.h"
#include "/usr/local/include/pcapplusplus/IPv4Layer.h"
#include "/usr/local/include/pcapplusplus/TcpLayer.h"
#include "/usr/local/include/pcapplusplus/HttpLayer.h"
#include "/usr/local/include/pcapplusplus/PcapFileDevice.h"
#include "/usr/local/include/pcapplusplus/RawPacket.h"
#include "HTTP.hpp"
#include "cpp/logger.cpp"
#include "cpp/color.hpp"
#include "cpp/calc.cpp"
#include <cstdio>
#include <iostream> 
#include <string>


int Process_HTTP(pcpp::RawPacket PKT) {
    pcpp::Packet parsedPacket(&PKT);
    pcpp::HttpRequestLayer* httpRequestLayer = parsedPacket.getLayerOfType<pcpp::HttpRequestLayer>();
    if (httpRequestLayer == NULL) {
		return 0;
	} else {
		Logger("Found HTTP  | ", 1);
		printf("\033[31m   |");
	}
	std::cout << std::endl
		<< RED << "<WOOFED>" << HIGH_BLUE << " Information |" << MAG << " HTTP method| => " << printHttpMethod(httpRequestLayer->getFirstLine()->getMethod()) << std::endl
		<< RED << "<WOOFED>" << HIGH_BLUE << " Information |" << MAG << " U R I      | => " << httpRequestLayer->getFirstLine()->getUri() << std::endl;
	std::cout
		<< RED << "<WOOFED>" << HIGH_BLUE << " Information |" << MAG << " Hostname   | => " << httpRequestLayer->getFieldByName(PCPP_HTTP_HOST_FIELD)->getFieldValue() << std::endl
		<< RED << "<WOOFED>" << HIGH_BLUE << " Information |" << MAG << " Full URL   | => " << httpRequestLayer->getUrl() << std::endl;

	std::cout << RED << "<WOOFED>" HIGH_BLUE << " Information |" << MAG << " User Agent | => " << httpRequestLayer->getFieldByName(PCPP_HTTP_USER_AGENT_FIELD)->getFieldValue() << "\n" << std::endl;
	string s = httpRequestLayer->getUrl();
	string STD_NET_STR = "http://";
	string prog = "./goul ";
	string arg = STD_NET_STR + httpRequestLayer->getUrl();
	Get_File_Extension_and_match(s, prog, arg, httpRequestLayer->getUrl());
	std::cout << YEL << "<WOOFED> " << HIGH_PINK << "Information |" << MAG << " Download | => Downloaded file to output-dir";
	
	return 0;
}