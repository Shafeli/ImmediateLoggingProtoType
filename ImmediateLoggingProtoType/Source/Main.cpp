#include <iostream>
#include <mutex>
#include "Logging/Logger.h"

int main()
{

    Valkara::Logger logTest("..\\logs", "LogTest");

    logTest.Log(Valkara::Logger::LogLevel::kInfo, "Starting insert system something");
    logTest.Log(Valkara::Logger::LogLevel::kDebug, "Debug Test: Loading something game assets failed");
    logTest.Log(Valkara::Logger::LogLevel::kWarning, "Warning Test: Something is a warning");
    logTest.Log(Valkara::Logger::LogLevel::kError, "Error Test: Something crashed!");

    return 0;
}   