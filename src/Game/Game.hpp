/*
** EPITECH PROJECT, 2022
** airplane
** File description:
** Game
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <bits/stdc++.h>
#include "State.hpp"
#include "GameState.hpp"
#include "LaunchState.hpp"

#define TITLE "SFML works!"

class Game {
    public:
        Game();
        ~Game();

        void run();
        void update();
        void render();
        void handleEvent();
        void updateDt() { _deltaTime = _clock_dt.restart().asSeconds(); };

    protected:
    private:
        void initWindow();
        void initStates();

        // variables
        sf::RenderWindow *_window;
        sf::Event _event;

        std::shared_ptr<std::vector<State *>> _states;
        sf::Font *_font;

        // delta time
        float _deltaTime;
        sf::Clock _clock_dt;
};
