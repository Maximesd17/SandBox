#ifndef __SANDBOX_SUBSCENE_SSPAUSEGAME__
#define __SANDBOX_SUBSCENE_SSPAUSEGAME__

#include "Game.hpp"
#include "Scenes/SubScenes/ASubScene.hpp"
#include "Components/Button.hpp"
#include <SFML/Graphics/RectangleShape.hpp>

namespace MySandBox
{
    namespace Scenes
    {
        namespace SubScenes
        {
            class SSPauseGame : public ASubScene
            {
                private:
                    uint menu_width = 420;
                    uint menu_height = 160; // 3 boutons * 40 height + les écarts entre boutons de 10 height 
                    uint button_width = 200;
                    uint button_height = 40;
                    MySandBox::Components::Button _button_continue;
                    MySandBox::Components::Button _button_menu;
                    MySandBox::Components::Button _button_exit;
                    sf::RectangleShape _pause_background_rect;
                    sf::RectangleShape _pause_menu_rect;
                public:
                    SSPauseGame(MySandBox::State &state, Game::Game &game);
                    ~SSPauseGame();
                    void events(sf::Event &event);
                    void update();
                    void display();
            };
        } // namespace SubScenes
        
    } // namespace Scenes
    
} // namespace MySandBox

#endif /*__SANDBOX_SUBSCENE_SSPAUSEGAME__*/