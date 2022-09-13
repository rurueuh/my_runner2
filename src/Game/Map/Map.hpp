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
        virtual ~Map();

        void update(const float &dt, sf::RenderWindow *window);
        void render(sf::RenderTarget *target);
        int getBlockLengthMostFar();

        float getMaxHeight(sf::Vector2f &posPlayer, sf::RenderWindow *window) const;

    protected:

        void move(const float &dt, sf::RenderWindow *window);

    private:
        std::vector< std::vector< sf::Sprite> > _sprites;
        sf::Texture _texture;

        const std::string _texturePath = "assets/ground.png";
        const sf::IntRect _spriteRect = sf::IntRect(243, 18, 78, 77);

        const float moveSpeed = 300.f;
};
