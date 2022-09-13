/*
** EPITECH PROJECT, 2022
** airplane
** File description:
** GameState
*/

#pragma once

#include "SFML.hpp"
#include "State.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include "DeadState.hpp"

class GameState : public State {
    public:
        GameState(sf::RenderWindow *target, sf::Font *font, std::shared_ptr<std::vector<State *>> *states);
        virtual ~GameState();

        void update(const float &dt, sf::RenderTarget *target);
        void render(sf::RenderTarget * = nullptr);
        void onWindowResize(sf::RenderTarget *target);

        void checkQuit();
    protected:
    private:
        Player *_player;
        Map *_map;
};
