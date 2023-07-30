#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

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

    // Parse the JSON file
    json jsonData = json::parse(file);

    // Print the parsed data
    std::cout << jsonData.dump(4) << std::endl;

    return 0;
}
