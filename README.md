# Valkara Logger

A lightweight, extensible C++14 logging library designed for real-time applications and game engines. Provides timestamped log messages, log levels, colored Windows console output, and persistent file logging.

## Features

- Log to both console and file
- Timestamped log entries
- Log levels: Debug, Info, Warning, Error
- Colored output on Windows console
- Simple API for integration into any C++ project

## Usage

### Basic Example

#include "Logger.h"
int main()
{

    Valkara::Logger logTest("..\\logs", "LogTest");

    logTest.Log(Valkara::Logger::LogLevel::kInfo, "Starting insert system something");
    logTest.Log(Valkara::Logger::LogLevel::kDebug, "Debug Test: Loading something game assets failed");
    logTest.Log(Valkara::Logger::LogLevel::kWarning, "Warning Test: Something is a warning");
    logTest.Log(Valkara::Logger::LogLevel::kError, "Error Test: Something crashed!");

    return 0;
} 



## Integration

1. Add `Logger.h` and `Logger.cpp` to your project.
2. Include the header: `#include "Logger.h"`
3. Create a logger instance and use the `Log` method.

## Requirements

- C++14 or newer
- Windows for colored console output

## License

MIT License

---

*Contributions and suggestions are welcome!*
