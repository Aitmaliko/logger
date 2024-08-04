#include "Logger.h"

Logger::Logger() {}

bool Logger::shouldPrintMessage(int timestamp, const std::string &message) {
    while (!msg_queue.empty() && msg_queue.front().first + TIME_LIMIT <= timestamp) {
        msg_map.erase(msg_queue.front().second);
        msg_queue.pop();
    }
    
    if (msg_map.find(message) != msg_map.end() && msg_map[message] + TIME_LIMIT > timestamp) {
        return false;
    }
    
    msg_map[message] = timestamp;
    msg_queue.push({timestamp, message});
    
    if (msg_queue.size() > MAX_SIZE) {
        msg_map.erase(msg_queue.front().second);
        msg_queue.pop();
    }
    
    return true;
}

bool Logger::clean(int timestamp) {
    if (!msg_queue.empty() && msg_queue.front().first + TIME_LIMIT > timestamp) {
        return false;
    }
    
    while (!msg_queue.empty() && msg_queue.front().first + TIME_LIMIT <= timestamp) {
        msg_map.erase(msg_queue.front().second);
        msg_queue.pop();
    }
    
    return true;
}

int Logger::loggerSize() {
    return msg_queue.size();
}
