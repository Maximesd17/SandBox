#include "LogManager.hpp"

/*********Constructor*********/
/* This build the object     */
/*********Constructor*********/
LogManager::LogManager() {

}

/*********Destructor*********/
/* This destroy the sandbox */
/*********Destructor*********/
LogManager::~LogManager() {
    
}

/********addLog*******/
/* add log in memory */
/********addLog*******/
void LogManager::addLog(const std::string& name, const std::string& state, const std::string& content) {
    _logs.push_back({ name, state, content });
}

/**********ClearLogs*********/
/* clear all logs in memory */
/**********ClearLogs*********/
void LogManager::removeAllLogs() {
    _logs.clear();
}


/**********saveLogsToFile*********/
/* save all logs in file         */
/**********saveLogsToFile*********/
void LogManager::saveLogsToFile(const std::string& filename) {
    std::ofstream file(filename);

    if (file.is_open()) {
        for (const Log& log : _logs) {
            file << log.name << ',' << log.state << ',' << log.content << '\n';
        }
        file.close();
        std::cout << "Logs saved to file: " << filename << std::endl;
    } else {
        std::cout << "Error opening file: " << filename << std::endl;
    }
}

/**********loadLogsFromFile*********/
/* load all logs from file         */
/**********loadLogsFromFile*********/
void LogManager::loadLogsFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (file.is_open()) {
        _logs.clear();
        std::string line;

        while (std::getline(file, line)) {
            std::string name, state, content;
            std::stringstream ss(line);
            std::getline(ss, name, ',');
            std::getline(ss, state, ',');
            std::getline(ss, content, ',');

            _logs.push_back({ name, state, content });
        }

        file.close();
        std::cout << "Logs loaded from file: " << filename << std::endl;
    } else {
        std::cout << "Error opening file: " << filename << std::endl;
    }
}

void LogManager::printLogs() {
    if (!_logs.empty())
        for (const Log& log : _logs) {
            std::cout << "Name: " << log.name << ", State: " << log.state << ", Content: " << log.content << std::endl;
        }
}