#include "SandBox.hpp"

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

    // JsonData jsonData = parser.parse_simple(json);
    // jsonData.print();

    GameMap map = parser.parse(json);

    // Display the map
    map.display();


    SandBox *game_instance;
    game_instance = new SandBox();


    game_instance->start();
    
    
    delete game_instance;
    return 0;
}
