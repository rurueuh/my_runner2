/*
** EPITECH PROJECT, 2022
** *
** File description:
** Gravity
*/

#pragma once

namespace GRAVITY {
    const int GRAVITY = 9.81;
    const int JUMP = 10;
}

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
};
