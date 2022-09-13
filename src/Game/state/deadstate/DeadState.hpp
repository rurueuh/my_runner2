/*
** EPITECH PROJECT, 2022
** my_runner2
** File description:
** DeadState
*/

#pragma once

#include "SFML.hpp"
#include "State.hpp"

class DeadState : public State {
    public:
        DeadState(sf::RenderWindow *, sf::Font *, std::shared_ptr<std::vector<State *>> *);
        virtual ~DeadState();

        void update(const float &dt, sf::RenderTarget *target);
        void render(sf::RenderTarget * = nullptr);
        void onWindowResize(sf::RenderTarget *target) {};

        void buttonToMenu();
        void buttonRestart();

        void checkQuit();
    protected:
    private:
        Text *_text;
        std::pair<Button *, void (DeadState::*)()> _button_to_menu;
        std::pair<Button *, void (DeadState::*)()> _button_restart;
};
