#include <iostream>
#include <sstream>
#include "stdlib.h"
#include "/usr/local/include/pcapplusplus/SystemUtils.h"
#include "/usr/local/include/pcapplusplus/Packet.h"
#include "/usr/local/include/pcapplusplus/EthLayer.h"
#include "/usr/local/include/pcapplusplus/IPv4Layer.h"
#include "/usr/local/include/pcapplusplus/TcpLayer.h"
#include "/usr/local/include/pcapplusplus/HttpLayer.h"
#include "/usr/local/include/pcapplusplus/PcapFileDevice.h"
#include "/usr/local/include/pcapplusplus/RawPacket.h"
#include "mod/banner.cpp"
#include "mod/pcaphead/pcapng.hpp"






int main(int argc, char* argv[]) {
    Load_banner(BNNR);
    string PcapNG_File  = argv[1];
    
    int printedPacketCount = 0;
    int packetCount = -1;
    pcpp::IFileReaderDevice* reader = pcpp::IFileReaderDevice::getReader(PcapNG_File);
    if (reader == NULL) {
		std::cerr << "[-] ERROR: Could not determin type - " << std::endl;
		return 1;
	}
	if (!reader->open()) {
		std::cerr << "[-] ERROR: Could not open the file, error - " << std::endl;
		return 1;
	}
    std::ofstream of;
	std::ostream* o = &std::cout;
	if (dynamic_cast<pcpp::PcapFileReaderDevice*>(reader) != NULL)
	{
		pcpp::PcapFileReaderDevice* pcapReader = dynamic_cast<pcpp::PcapFileReaderDevice*>(reader);
		printedPacketCount = Loader(pcapReader, o, packetCount);
	}
	else if (dynamic_cast<pcpp::SnoopFileReaderDevice*>(reader) != NULL)
	{
		pcpp::SnoopFileReaderDevice* snoopReader = dynamic_cast<pcpp::SnoopFileReaderDevice*>(reader);
		printedPacketCount = Loader(snoopReader, o, packetCount);
	}
    (*o) << "[*] Packets Loaded ->  " << printedPacketCount << std::endl;
	reader->close();
	delete reader;
	return 0;
} 