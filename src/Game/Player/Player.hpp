/*
** EPITECH PROJECT, 2022
** my_runner2
** File description:
** Player
*/

#pragma once

#include "SFML.hpp"
#include "Gravity.hpp"
#include "Animation.hpp"


class Player {
    public:
        Player();
        ~Player();

        void update(const float &dt);
        void render(sf::RenderTarget *target);

    protected:
    private:
        Gravity *_gravity;
        Animation *_animation;

        sf::Sprite _sprite;
        sf::Texture _texture;
        
        const sf::IntRect PLAYER_SPRITE_RECT = {93, 31, 133, 181};
};
