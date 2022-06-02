#include <iostream>
#include <fstream>
#include <string>
#include "head/BANNER.hpp"
using namespace std;

int Load_banner(string filename) {
    cout << "\x1b[H\x1b[2J\x1b[3J";
    string data;
    ifstream banner (filename);
    if (banner.is_open()) {
        while (getline(banner, data)) {
            cout << data << "\n";
        }
        banner.close();
    } else cout << "[-] Error - FATAL: Could not load banner file";
    return 0;
}

