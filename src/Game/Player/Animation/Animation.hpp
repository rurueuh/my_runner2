/*
** EPITECH PROJECT, 2022
** my_runner2
** File description:
** Animation
*/

#pragma once

#include "SFML.hpp"

class Animation {
    public:
        Animation(sf::Sprite *);
        ~Animation();

        void update();

    protected:
    private:
        const std::array<sf::IntRect, 10> _frames = {
            sf::IntRect(93, 31, 133, 181),
            sf::IntRect(241, 49, 147, 178),
            sf::IntRect(417, 62, 149, 172),
            sf::IntRect(625, 51, 125, 187),
            sf::IntRect(789, 61, 130, 184),
            sf::IntRect(80, 270, 131, 177),
            sf::IntRect(241, 271, 150, 180),
            sf::IntRect(414, 280, 154, 168),
            sf::IntRect(604, 274, 137, 187),
            sf::IntRect(788, 270, 132, 183)
        };
        const float _frameTime = 0.1f;

        sf::Clock _clock;
        sf::Sprite *_sprite;
};
