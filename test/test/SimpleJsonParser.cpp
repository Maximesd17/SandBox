#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

template<typename K, typename V>
class SimpleJsonParser {
public:
  std::multimap<K, V> parse(const std::string& json) {
    std::multimap<K, V> result;

    std::istringstream jsonStream(json);
    char c;

    K key;
    V value;
    bool isKey = true;

    while (jsonStream >> c) {
      if (c == ',') {
	if (!key.empty() && !value.empty()) {
	  result.insert(std::make_pair(key, value));
	  key.clear();
	  value.clear();
	}
	isKey = true;
      } else if (c == '{') {
	key.clear();
	value.clear();
	isKey = true;
      } else if (c == '}') {
	if (!key.empty() && !value.empty()) {
	  result.insert(std::make_pair(key, value));
	}
      } else if (c == '"') {
	if (isKey) {
	  std::getline(jsonStream, key, '"');
	  isKey = false;
	} else {
	  std::getline(jsonStream, value, '"');
	  if (!key.empty() && !value.empty()) {
	    result.insert(std::make_pair(key, value));
	    key.clear();
	    value.clear();
	  }
	}
      } else if (c == ':') {
	if (!isKey) {
	  std::string temp;
	  jsonStream >> temp;
	  value = temp;
	  result.insert(std::make_pair(key, value));
	  key.clear();
	  value.clear();
	}
      }
    }

    return result;
  }
};

int main(int argc, char* argv[]) {
  if(argc < 2) {
    std::cerr << "Please provide a file path as a command line argument.\n";
    return 1;
  }

  std::ifstream file(argv[1]);

  if (!file) {
    std::cerr << "Could not open file: " << argv[1] << '\n';
    return 1;
  }

  std::string json((std::istreambuf_iterator<char>(file)),
		   std::istreambuf_iterator<char>());

  SimpleJsonParser<std::string, std::string> parser;
  auto result = parser.parse(json);

  for (const auto& [key, value] : result) {
    std::cout << "Key: " << key << ", Value: " << value << '\n';
  }

  return 0;
}
