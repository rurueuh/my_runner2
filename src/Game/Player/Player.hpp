/*
** EPITECH PROJECT, 2022
** my_runner2
** File description:
** Player
*/

#pragma once

#include "SFML.hpp"

class Player {
    public:
        Player();
        ~Player();

        void update(const float &dt);
        void render(sf::RenderTarget *target);

    protected:
    private:
        sf::Sprite _sprite;
        sf::Texture _texture;
};
