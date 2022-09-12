/*
** EPITECH PROJECT, 2022
** *
** File description:
** Gravity
*/

#pragma once

#include "SFML.hpp"

class Gravity {
    public:
        Gravity(sf::Sprite *sprite);
        ~Gravity();

        void update(const float &dt);
        // void render(sf::RenderTarget *target);
        void setGravity(const float &gravity);

    protected:
    private:
        sf::Sprite *_sprite;
        float _gravity;

        const int JUMP = 10;
        const int GRAVITY_FORCE = 9.81;
};
