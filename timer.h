#pragma once

#include <iostream>
#include <chrono>

class Timer
{
public:
    void start()
    {
        startTime = std::chrono::system_clock::now();
        running = true;
    }

    void stop()
    {
        endTime = std::chrono::system_clock::now();
        running = false;
    }

    void reset()
    {
        stop();
        start();
    }

    double elapsedMilliseconds()
    {
        std::chrono::time_point<std::chrono::system_clock> endTime;

        if(running)
            endTime = std::chrono::system_clock::now();
        else
            endTime = endTime;

        return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
    }

    double elapsedSeconds()
    {
        return elapsedMilliseconds() / 1000.0;
    }

private:
    bool                                               running = false;
    std::chrono::time_point<std::chrono::system_clock> startTime, endTime;
};
