#ifndef LOGGER_H
#define LOGGER_H

#include <unordered_map>
#include <string>
#include <queue>
#include <utility>

class Logger {
public:
    Logger();
    bool shouldPrintMessage(int timestamp, const std::string &message);
    bool clean(int timestamp);
    int loggerSize();
    
private:
    std::unordered_map<std::string, int> msg_map;
    std::queue<std::pair<int, std::string>> msg_queue;
    const int TIME_LIMIT = 10;
    const int MAX_SIZE = 100;
};

#endif 
