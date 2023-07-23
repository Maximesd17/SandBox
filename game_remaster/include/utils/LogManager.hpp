#ifndef ______LOGMANAGER_HPP___
#define ______LOGMANAGER_HPP___


#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

struct Log {
  std::string name;
  std::string state;
  std::string content;
};

class LogManager {
private:
  std::vector<Log> _logs;

public:
  LogManager();
  ~LogManager();
  void addLog(const std::string& name, const std::string& state, const std::string& content);
  void removeAllLogs();
  void saveLogsToFile(const std::string& filename);
  void loadLogsFromFile(const std::string& filename);
  void printLogs();
};


#endif //______LOGMANAGER_HPP___
