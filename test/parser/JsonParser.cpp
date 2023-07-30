#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <variant>

#define INDENT(n) std::string(n, '\t')

class JsonPair {
public:
  JsonPair(const std::string& key, const std::string& value) : key_(key), value_(value) {}
  std::string getKey() const { return key_; }
  std::string getValue() const { return value_; }
private:
  std::string key_;
  std::string value_;
};



class JsonData {
public:
  void addObject(const JsonPair& pair) { _objects[pair.getKey()] = pair.getValue(); }
  void addArrayElement(const std::string& element) { _array.push_back(element); }
  void addArrayElement(const JsonData& jsonData) { _nestedArrays.push_back(jsonData); }
  void addObject(const std::string& key, const JsonData& jsonData) {
    _nestedObjects[key] = jsonData;
  }

private:
  std::map<std::string, std::string> _objects;
  std::vector<std::string> _array;
  std::vector<JsonData> _nestedArrays;
  std::map<std::string, JsonData> _nestedObjects;

public:
  void print(int indentLevel = 0) const {
    std::cout << INDENT(indentLevel) << "{\n";

    // Print objects
    for (const auto& obj : _objects)
      std::cout << INDENT(indentLevel + 1) << "\"" << obj.first << "\": \"" << obj.second << "\",\n";

    // Print array
    if (!_array.empty()) {
      std::cout << INDENT(indentLevel + 1) << "\"_arrayb\": [\n";
      for (size_t i = 0; i < _array.size(); ++i) {
	std::cout << INDENT(indentLevel + 2) << "\"" << _array[i] << "\"";
	if (i != _array.size() - 1)
	  std::cout << ",";
	std::cout << "\n";
      }
      std::cout << INDENT(indentLevel + 1) << "],\n";
    }

    // Print nested arrays
    for (const auto& nestedArray : _nestedArrays) {
      std::cout << INDENT(indentLevel + 1) << "\"_arraya\": [\n";
      nestedArray.print(indentLevel + 2);
      std::cout << INDENT(indentLevel + 1) << "],\n";
    }

    // Print nested objects
    for (const auto& nestedObj : _nestedObjects) {
      std::cout << INDENT(indentLevel + 1) << "\"" << nestedObj.first << "\": ";
      nestedObj.second.print(indentLevel + 1);
      std::cout << ",\n";
    }

    std::cout << INDENT(indentLevel) << "}\n";
  }

};

class JsonParser {
public:
  JsonData parse(const std::string& json) {

    JsonData jsonData;
    std::string key, value;
    bool inString = false;
    bool inKey = false;
    size_t start = 0;

    for (size_t i = 0; i < json.size(); ++i) 
    {
      char c = json[i];

      if (inString) 
      {
	if (c == '\"' && json[i - 1] != '\\') 
  {
	  inString = false;
	  if (inKey) {
	    key = json.substr(start, i - start);
	    inKey = false;
	  } else {
	    value = json.substr(start, i - start);
	    jsonData.addObject(JsonPair(key, value));
	  }
	}
      }
       else 
       {
	if (c == '\"') 
  {
	  inString = true;
	  start = i + 1;
	} 
  else if (c == '{') 
  {
	  if (inKey) 
    {
	    // Nested object
	    inKey = false;
	    size_t closingBraceIndex = findClosingBraceIndex(json, i);
	    std::string nestedJson = json.substr(i, closingBraceIndex - i + 1);
	    JsonParser parser;
	    JsonData nestedData = parser.parse(nestedJson);
	    jsonData.addObject(key, nestedData);
	    i = closingBraceIndex;
	  } 
    else 
    {
	    inKey = true;
	  }
	} 
  else if (c == '[') 
  {
	  if (inKey) 
    {
	    // Array
	    inKey = false;
	    size_t closingBracketIndex = findClosingBracketIndex(json, i);
	    std::string arrayJson = json.substr(i, closingBracketIndex - i + 1);
	    JsonParser parser;
	    JsonData arrayData = parser.parseArray(arrayJson);
	    jsonData.addArrayElement(arrayData);
	    i = closingBracketIndex;
	  } 
    else 
    {
	    inKey = true;
	  }
	}
      }
    }

    return jsonData;
  }

  JsonData parseArray(const std::string& jsonArray) {
    JsonData arrayData;
    size_t start = 0;
    bool inString = false;

    for (size_t i = 0; i < jsonArray.size(); ++i) {
      char c = jsonArray[i];

      if (inString) {
	if (c == '\"' && jsonArray[i - 1] != '\\') {
	  inString = false;
	}
      } else {
	if (c == '\"') {
	  inString = true;
	  start = i + 1;
	} else if (c == '{') {
	  size_t closingBraceIndex = findClosingBraceIndex(jsonArray, i);
	  std::string nestedJson = jsonArray.substr(i, closingBraceIndex - i + 1);
	  JsonParser parser;
	  JsonData nestedData = parser.parse(nestedJson);
	  arrayData.addArrayElement(nestedData);
	  i = closingBraceIndex;
	} else if (c == ']') {
	  if (i > start) {
	    std::string element = jsonArray.substr(start, i - start);
	    arrayData.addArrayElement(element);
	  }
	}
      }
    }

    return arrayData;
  }

private:
  size_t findClosingBraceIndex(const std::string& json, size_t start) {
    int count = 1;
    for (size_t i = start + 1; i < json.size(); ++i) {
      if (json[i] == '{')
	++count;
      else if (json[i] == '}')
	--count;

      if (count == 0)
	return i;
    }
    return std::string::npos;
  }

  size_t findClosingBracketIndex(const std::string& jsonArray, size_t start) {
    int count = 1;
    for (size_t i = start + 1; i < jsonArray.size(); ++i) {
      if (jsonArray[i] == '[')
	++count;
      else if (jsonArray[i] == ']')
	--count;

      if (count == 0)
	return i;
    }
    return std::string::npos;
  }
};

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " <path_to_json_file>\n";
    return 1;
  }

  std::ifstream file(argv[1]);
  if (!file) {
    std::cout << "Error opening file: " << argv[1] << std::endl;
    return 1;
  }

  std::string json((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

  JsonParser parser;
  JsonData jsonData = parser.parse(json);

  jsonData.print();

  return 0;
}
