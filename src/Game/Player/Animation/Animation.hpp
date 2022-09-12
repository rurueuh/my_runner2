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
            sf::IntRect(93, 31, 133, 186),
            sf::IntRect(241, 49, 147, 186),
            sf::IntRect(417, 62, 149, 186),
            sf::IntRect(625, 51, 125, 186),
            sf::IntRect(789, 61, 130, 186),
            sf::IntRect(80, 270, 131, 186),
            sf::IntRect(241, 271, 150, 186),
            sf::IntRect(414, 280, 154, 186),
            sf::IntRect(604, 274, 137, 186),
            sf::IntRect(788, 270, 132, 186)
        };
        const float _frameTime = 0.1f;

        sf::Clock _clock;
        sf::Sprite *_sprite;
};
