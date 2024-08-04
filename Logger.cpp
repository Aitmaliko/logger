#include "Logger.h"

Logger::Logger() {}

//function to check if the message should be printed at the given timestamp
bool Logger::shouldPrintMessage(int timestamp, const std::string &message) {
    //we remove messages older than the TIME_LIMIT
    while (!msg_queue.empty() && msg_queue.front().first + TIME_LIMIT <= timestamp) {
        msg_map.erase(msg_queue.front().second);
        msg_queue.pop();
    }
    //check
    if (msg_map.find(message) != msg_map.end() && msg_map[message] + TIME_LIMIT > timestamp) {
        return false;
    }
    //update the meessage
    msg_map[message] = timestamp;
    msg_queue.push({timestamp, message});

    //to ensure that logger doesnt exeed the maxsize
    if (msg_queue.size() > MAX_SIZE) {
        msg_map.erase(msg_queue.front().second);
        msg_queue.pop();
    }
    
    return true;
}
//clean the logger at the given timestamp
bool Logger::clean(int timestamp) {
    //we should check if any message processing
    if (!msg_queue.empty() && msg_queue.front().first + TIME_LIMIT > timestamp) {
        return false;
    }
    //remove all messages older than the TIME_LIMIT
    while (!msg_queue.empty() && msg_queue.front().first + TIME_LIMIT <= timestamp) {
        msg_map.erase(msg_queue.front().second);
        msg_queue.pop();
    }
    
    return true;
}

//get the current size
int Logger::loggerSize() {
    return msg_queue.size();
}
