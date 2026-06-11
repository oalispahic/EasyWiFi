//
// Created by Omar Alispahic  on 11. 6. 2026..
//

#include "../include/easywifi.h"

std::vector<std::string> networkConnector::execute(const std::string &cmd) {
    std::vector<std::string> lines;

    FILE *pipe = popen(cmd.c_str(),"r");

    char buffer[256];
    while (fgets(buffer,sizeof(buffer),pipe)) {
        std::string line(buffer);

        if (line.empty() && line.back() == '\n') line.pop_back();
        lines.push_back(line);
    }
    return lines;
}

connectionStatus networkConnector::scanNetworks() {

}

