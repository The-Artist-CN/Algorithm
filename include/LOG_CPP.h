#ifndef LOG_CPP_H
#define LOG_CPP_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <mutex>

// 日志级别枚举
enum class Level {
    DEBUG,
    INFO,
    WARN,
    ERROR,
    FATAL
};

// 日志类
class Logger {
public:
    // 构造函数，指定日志文件名
    Logger(const std::string& filename = "log.txt") : logFile(filename, std::ios::app) {
        if (!logFile.is_open()) {
            throw std::runtime_error("Failed to open log file!");
        }
    }

    // 日志记录函数
    void log(Level level, const std::string& message, const std::string& file = "", int line = -1) {
        std::lock_guard<std::mutex> lock(logMutex); // 线程安全

        std::string levelStr;
        switch (level) {
            case Level::DEBUG: levelStr = "DEBUG"; break;
            case Level::INFO:  levelStr = "INFO";  break;
            case Level::WARN:  levelStr = "WARN";  break;
            case Level::ERROR: levelStr = "ERROR"; break;
            case Level::FATAL: levelStr = "FATAL"; break;
        }

        auto now = std::chrono::system_clock::now();
        auto now_time = std::chrono::system_clock::to_time_t(now);
        std::tm now_tm = *std::localtime(&now_time);

        std::ostringstream oss;
        oss << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S") << " [" << levelStr << "] ";

        if (!file.empty() && line != -1) {
            oss << "[" << file << ":" << line << "] ";
        }

        oss << message;

        logFile << oss.str() << std::endl;
        std::cout << oss.str() << std::endl; // 同时输出到控制台
    }

    // 析构函数
    ~Logger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }

private:
    std::ofstream logFile; // 日志文件
    std::mutex logMutex;   // 互斥锁，确保线程安全
};

// 全局日志对象
static Logger globalLogger;

// 宏定义，简化日志调用
#define LOG_DEBUG(message) globalLogger.log(Level::DEBUG, message, __FILE__, __LINE__)
#define LOG_INFO(message)  globalLogger.log(Level::INFO,  message, __FILE__, __LINE__)
#define LOG_WARN(message)  globalLogger.log(Level::WARN,  message, __FILE__, __LINE__)
#define LOG_ERROR(message) globalLogger.log(Level::ERROR, message, __FILE__, __LINE__)
#define LOG_FATAL(message) globalLogger.log(Level::FATAL, message, __FILE__, __LINE__)

#endif // LOG_CPP_H

