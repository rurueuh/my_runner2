/*
** EPITECH PROJECT, 2022
** my_runner2
** File description:
** Paralax
*/

#pragma once

#include "SFML.hpp"

typedef struct paralax_s {
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f speed;
} paralax_t;

#define PARALAX_NB 2
#define PARALAX_SPEED 80

class Paralax {
    public:
        Paralax(sf::Vector2u);
        ~Paralax();

        void update(const float &dt, sf::Vector2u size);

        void render(sf::RenderTarget *target);

    protected:
    private:
        std::array<paralax_t, PARALAX_NB> _paralax;

        const std::array<std::string, PARALAX_NB> _path = {
            "assets/paralax1.png",
            "assets/paralax2.png"
        };
};
