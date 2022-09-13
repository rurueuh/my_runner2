/*
** EPITECH PROJECT, 2022
** my_runner2
** File description:
** Bestscore
*/

#pragma once

#include "SFML.hpp"

class Bestscore {
    public:
        Bestscore(sf::Font *, sf::Vector2f);
        ~Bestscore();

        void render(sf::RenderTarget *);

    protected:
    private:
        Text *_text;
};
