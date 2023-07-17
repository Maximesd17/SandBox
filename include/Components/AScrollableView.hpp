/*
** EPITECH PROJECT, 2023
** final-project
** File description:
** ScrollableView
*/

#ifndef SCROLLABLEVIEW_HPP_
#define SCROLLABLEVIEW_HPP_

#include <SFML/Graphics.hpp>

namespace MySandBox {
    namespace Components {
        class AScrollableView {
        public:
            AScrollableView(sf::FloatRect size);
            ~AScrollableView();
            virtual void events(sf::Event& event);
            virtual void update();
        protected:
            void setView(sf::RenderWindow& window);

            sf::View _view;
            sf::FloatRect _viewPort;
            float _height;
            sf::RectangleShape _scrollbar;
            sf::RectangleShape _scrollbar_track;
        private:
            bool _is_scrollable;
            bool _scrollbar_clicked;
        };
    }
}

#endif /* !SCROLLABLEVIEW_HPP_ */
