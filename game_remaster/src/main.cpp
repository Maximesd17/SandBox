#include "SandBox.hpp"

int main(void)
{
    SandBox *game_instance;
    game_instance = new SandBox();


    game_instance->start();
    
    
    delete game_instance;
    return 0;
}