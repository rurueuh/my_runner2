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

        void update(const float &dt, int height);
        // void render(sf::RenderTarget *target);
        void setGravity(const float &gravity);
        bool getGrounded() const { return this->isGrounded; }

        const static int JUMP = -6;
        const static int GRAVITY_FORCE = 9.81;
    protected:
    private:
        sf::Sprite *_sprite;
        float _gravity;

        bool isGrounded;

};
