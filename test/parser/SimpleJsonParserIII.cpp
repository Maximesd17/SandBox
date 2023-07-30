#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <variant>

class JsonPair
{
public:
  std::string _key;
  std::string _value;

  JsonPair() = default;

  JsonPair(const std::string& key, const std::string& value)
    : _key(key), _value(value)
  {}
};

template <typename T>
class JsonObject {
public:
  std::map<std::string, T> _object;

  void insert(const std::string& key, const T& value) {
    _object[key] = value;
  }
};

template <typename T>
class JsonArray {
public:
  std::vector<T> _array;

  void push_back(const T& value) {
    _array.push_back(value);
  }
};

std::string trim(const std::string& str,
                 const std::string& whitespace = " \t")
{
  const auto strBegin = str.find_first_not_of(whitespace);
  if (strBegin == std::string::npos)
    return "";
  const auto strEnd = str.find_last_not_of(whitespace);
  const auto strRange = strEnd - strBegin + 1;
  return str.substr(strBegin, strRange);
}

std::string removeQuotes(const std::string& input)
{
  std::string output;
  for (char c : input)
  {
    if (c != '\"' && c != ',')
      output += c;
  }
  return output;
}

using JsonData = std::variant<JsonObject<JsonPair>, JsonArray<JsonPair>>;

JsonData parseJson(std::istream& iss, int indent = 0) {
  std::string token;
  bool isObject = false;
  while (std::getline(iss, token)) {
    if (token.find('{') != std::string::npos) {
      isObject = true;
      break;
    } else if (token.find('[') != std::string::npos) {
      isObject = false;
      break;
    }
  }
  if (isObject) {
    JsonObject<JsonPair> jsonObject;
    while (std::getline(iss, token)) {
      if (token.find('}') != std::string::npos)
        break;
      size_t colonPos = token.find(':');
      if (colonPos != std::string::npos) {
        std::string key = removeQuotes(trim(token.substr(0, colonPos)));
        std::string value = removeQuotes(trim(token.substr(colonPos + 1)));
        jsonObject.insert(key, JsonPair(key, value));
      }
    }
    return jsonObject;
  } else {
    JsonArray<JsonPair> jsonArray;
    while (std::getline(iss, token)) {
      if (token.find(']') != std::string::npos)
        break;
      size_t colonPos = token.find(':');
      if (colonPos != std::string::npos) {
        std::string key = removeQuotes(trim(token.substr(0, colonPos)));
        std::string value = removeQuotes(trim(token.substr(colonPos + 1)));
        jsonArray.push_back(JsonPair(key, value));
      }
    }
    return jsonArray;
  }
}

int main(int argc, char** argv) {
  std::vector<JsonData> jsonDataList; // Store all parsed JSON objects

  for (int i = 1; i < argc; i++) {
    std::ifstream file(argv[i]);
    if (!file)
      std::cerr << "Oupsi le fichier " << argv[i] << " s'est pas ouvert !" << std::endl;
    
    JsonData jsonValue = parseJson(file);
    jsonDataList.push_back(jsonValue); // Add the parsed JSON object to the list
  }

  // Print all JSON objects
  for (const auto& jsonData : jsonDataList) {
    if (std::holds_alternative<JsonObject<JsonPair>>(jsonData)) {
      for (const auto& pair : std::get<JsonObject<JsonPair>>(jsonData)._object)
        std::cout << "Keys: " << pair.first << ", Value: " << pair.second._value << std::endl;
    } else {
      int index = 0;
      for (const auto& pair : std::get<JsonArray<JsonPair>>(jsonData)._array)
        std::cout << "Index: " << index++ << ", Key: " << pair._key << ", Value: " << pair._value << std::endl;
    }
  }

  return 0;
}
