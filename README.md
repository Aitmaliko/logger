# logger
repository for the task

This is the code for the Task2 by Nfactorial. I solved this task by using C++. There are overall 3 files that are needed to complete this task. First is the "main.cpp", which has the code by given explanation. "Logger.h" and "Logger.cpp", where functions located. 

I created a class called Logger with the necessary variables and functions. The class is defined in Logger.h and implemented in Logger.cpp. The member variables:"msg_map" - an unordered map to keep track of the last printed timestamp for each message. "msg_queue" - a queue to store messages along with their timestamps in the order they are received. "TIME_LIMIT" - a constant to represent the 10-second limit. "MAX_SIZE" - a constant to represent the maximum size of the logger (100 messages).

Functions are explained in the comments.


Do this to compile and run:
1)g++ -o logger main.cpp Logger.cpp
2)./logger

I hope that everything is correct. Thank you!
