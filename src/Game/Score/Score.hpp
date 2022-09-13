/*
** EPITECH PROJECT, 2022
** my_runner2
** File description:
** Score
*/

#pragma once

#include "SFML.hpp"

class Score {
    public:
        Score(sf::Font *);
        ~Score();

        void update();
        void render(sf::RenderTarget *target);

    protected:
    private:
        Text *_text;
        sf::Clock _clock;
};
