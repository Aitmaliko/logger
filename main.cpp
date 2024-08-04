#include <iostream>
#include "Logger.h"

int main() {
    Logger logger;
    
    std::cout << std::boolalpha;
    std::cout << logger.shouldPrintMessage(1, "foo") << std::endl;  // true
    std::cout << logger.shouldPrintMessage(2, "bar") << std::endl;  // true
    std::cout << logger.shouldPrintMessage(3, "foo") << std::endl;  // false
    std::cout << logger.shouldPrintMessage(8, "bar") << std::endl;  // false
    std::cout << logger.shouldPrintMessage(10, "foo") << std::endl; // false
    std::cout << logger.shouldPrintMessage(11, "foo") << std::endl; // true

    std::cout << "Logger size: " << logger.loggerSize() << std::endl; // 2
    std::cout << logger.clean(11) << std::endl; // false
    std::cout << logger.clean(12) << std::endl; // true

    return 0;
}
