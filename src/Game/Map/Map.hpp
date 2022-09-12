/*
** EPITECH PROJECT, 2022
** my_runner2
** File description:
** Map
*/

#pragma once

#include "SFML.hpp"

class Map {
    public:
        Map();
        ~Map();

        void update(const float &dt);
        void render(sf::RenderTarget *target);

        float getMaxHeight(sf::Vector2f &posPlayer, sf::RenderWindow *window) const;

    protected:
    private:
        std::vector< std::vector< sf::Sprite> > _sprites;
        sf::Texture _texture;

        const std::string _texturePath = "assets/ground.png";
        const sf::IntRect _spriteRect = sf::IntRect(243, 18, 78, 77);
};
