#ifndef EASYWIFI_LIBRARY_H
#define EASYWIFI_LIBRARY_H

#include <cstdio>
#include <vector>
#include <string>

enum class connectionStatus {
    CONNECTED,
    DISCONNECTED,
    BAD_PASSWD,
    SSID_NOT_FOUND,
    OK,
    ERR
};


struct networkInfo {
    std::string ssid;
    std::string pwd;
    std::string signal_strength;
};

struct connectionState {
    bool connected;
    std::string ssid;
    std::string interface; // wlan0
};


class networkConnector {
public:
    std::vector<networkInfo> networks;

    networkConnector() = default;

    connectionStatus scanNetworks();

    connectionStatus connectNetwork(std::string ssid, std::string pwd);

    connectionStatus disconnectNetwork(std::string ssid, std::string pwd);

    connectionState getStatus();

    connectionStatus radioOn();



    static std::vector<std::string> execute(const std::string &cmd);
};

#endif // EASYWIFI_LIBRARY_H