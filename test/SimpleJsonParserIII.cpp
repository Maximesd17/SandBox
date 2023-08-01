#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class JsonPair
{
public:
  std::string _key;
  std::string _value;

  JsonPair(const std::string&		key,
	   const std::string&		value)
    : _key(key), _value(value)
  {}
};


std::string trim (const std::string&	str,
		  const std::string&	whitespace = " \t")
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


std::vector<JsonPair> parseJson(std::istream& iss, int indent = 0) {
  std::string token;
  std::vector<JsonPair> jsonPairs;
  while (std::getline(iss, token)) {
    size_t colonPos = token.find(':');
    if (colonPos != std::string::npos)
      {
	std ::string key = removeQuotes(trim(token.substr(0, colonPos)));
	std ::string value = removeQuotes(trim(token.substr(colonPos + 1)));
	jsonPairs.push_back(JsonPair(key, value));
	
      }
  }
  return jsonPairs;
}

int main(int argc, char** argv)
{
  for (int i = 1; i < argc; i++)
    {
      std::ifstream file(argv[i]);
      if (!file)
	std::cerr << "Oupsi le fichier " << argv[i] << " s'est pas ouvert !" << std::endl;
      std::vector<JsonPair> jsonPairs = parseJson(file);


      for (JsonPair pair : jsonPairs)
	std::cout << "Keys: " << pair._key << ", Value: " << pair._value <<std::endl; 
    }
  return 0;
}