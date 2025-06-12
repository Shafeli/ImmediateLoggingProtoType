#pragma once
#include <fstream>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// when creating a logger, the file name you give will be the name of the txt file
//
//     inline static Logger m_fileLog{ "LogFolderPathStr", "LogFileName" };
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Valkara
{

    class Logger
    {
        std::ofstream m_logFile;
        std::string m_logFilePath;
        std::string m_logFolderPath;

#ifdef _WIN32
        void* m_console = nullptr;
#endif
    public:

        enum class LogLevel
        {
            kDebug,
            kInfo,
            kWarning,
            kError
        };

        explicit Logger(const std::string& folderPath, const std::string& logFileName);
        ~Logger();

        void Log(LogLevel level, const std::string& message);

    private:
        std::string GetCurrentTimeString();
        void CloseFile();
    };

}
