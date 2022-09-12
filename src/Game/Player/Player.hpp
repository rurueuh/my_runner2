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
#include "Map.hpp"


class Player {
    public:
        Player(Map *map);
        ~Player();

        void update(const float &dt, sf::RenderWindow *window);
        void render(sf::RenderTarget *target);

        void jump();

    protected:
    private:
        Gravity *_gravity;
        Animation *_animation;
        Map *_map;

        sf::Sprite _sprite;
        sf::Texture _texture;
        
        const sf::IntRect PLAYER_SPRITE_RECT = {93, 31, 133, 181};
};
