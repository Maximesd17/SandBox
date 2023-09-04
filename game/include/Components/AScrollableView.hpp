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
            AScrollableView(sf::Vector2f size, sf::Vector2u window_size, bool is_scrollable = false);
            ~AScrollableView();
            virtual void events(sf::Event& event);
            virtual void update();
            virtual void display(sf::RenderWindow& window);
        protected:
            void checkScrollbar(sf::Vector2i mouse_pos);
            void setView(sf::RenderWindow& window);

            sf::View _view;
            sf::FloatRect _viewPort;
            sf::Vector2f _size;
            sf::RectangleShape _scrollbar;
            sf::RectangleShape _scrollbar_track;
        private:
            bool _is_scrollable;
            bool _scrollbar_clicked;
            sf::Vector2u _window_size;
        };
    }
}

#endif /* !SCROLLABLEVIEW_HPP_ */
