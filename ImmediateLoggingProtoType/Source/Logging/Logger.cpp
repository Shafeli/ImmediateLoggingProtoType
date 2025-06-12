#include "Logger.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

#ifdef _WIN32
#include <windows.h>
#endif

#define ACTIVE 1

Valkara::Logger::Logger(const std::string& folderPath, const std::string& logFileName)
    : m_logFilePath(folderPath)
    , m_logFolderPath(folderPath)
{
    m_console = GetStdHandle(STD_OUTPUT_HANDLE);
    if (m_console == INVALID_HANDLE_VALUE)
    {
        std::cerr << "Failed to get console handle." << std::endl;
        return;
    }

    m_logFilePath = m_logFilePath + "\\" + logFileName;
    m_logFilePath = m_logFilePath + ".txt";
    m_logFile.open(m_logFilePath, std::ios::out | std::ios::app);
}

Valkara::Logger::~Logger()
{
    if (m_logFile.is_open()) 
    {
        /*Log(LogLevel::kInfo, "File Closed by Destructor Control");*/
        m_logFile.close();
    }
}

void Valkara::Logger::Log(LogLevel level, const std::string& message)
{
#if ACTIVE
    if (!m_logFile.is_open())
    {
        SetConsoleTextAttribute(m_console, 12);
        std::cout << "Logging Failed... File is closed" << std::endl;
        SetConsoleTextAttribute(m_console, 15);
        return;
    }

    std::string levelString;

    switch (level)
    {
    case LogLevel::kInfo:

#ifdef _WIN32
        // setting the color to green
        SetConsoleTextAttribute(m_console, 10);
#endif
        levelString = "[~INFO~]";
        break;

    case LogLevel::kDebug:
#ifdef _WIN32
        //setting color to yellow
        SetConsoleTextAttribute(m_console, 14);
#endif
        levelString = "[~DEBUG~]";
        break;

    case LogLevel::kWarning:
#ifdef _WIN32
        //setting color to purple
        SetConsoleTextAttribute(m_console, 13);
#endif
        levelString = "[~WARNING~]";
        break;

    case LogLevel::kError:
#ifdef _WIN32
        // setting color to red 
        SetConsoleTextAttribute(m_console, 12);
#endif
        levelString = "[~ERROR~]";
        break;
    }

    const std::string fullLog = GetCurrentTimeString() + " " + levelString + " " + message;

    std::cout << fullLog << std::endl; // write to console
    m_logFile << fullLog << std::endl; // write to file
#ifdef _WIN32
    // resets color to base white
    SetConsoleTextAttribute(m_console, 15);
#endif // 


#endif
}

std::string Valkara::Logger::GetCurrentTimeString()
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    std::tm tm;
#ifdef _WIN32
    localtime_s(&tm, &now_c); // Windows
#else
    localtime_r(&now_c, &tm); // POSIX
#endif

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

void Valkara::Logger::CloseFile()
{
    if (m_logFile.is_open())
    {
        /*Log(LogLevel::kInfo, "File Closed by user Control");*/
        m_logFile.close();
    }
}
