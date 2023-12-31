#ifndef __SANDBOX_SUBSCENE_WINGAME__
#define __SANDBOX_SUBSCENE_WINGAME__

#include "Game.hpp"
#include "ASubScene.hpp"
#include "Components/Button.hpp"
namespace MySandBox {
    namespace Scenes {
        namespace SubScenes {
            class SSWinGame : public ASubScene {
                private:
                    MySandBox::Components::Button _return_button;
                    MySandBox::Components::Button _restart_button;
                public:
                    SSWinGame(MySandBox::State &state, Game::Game &game);
                    ~SSWinGame();
                    void events(sf::Event &event);
                    void update();
                    void display();
            };
        };
    };
};

#endif /*!__SANDBOX_SUBSCENE_WINGAME__*/