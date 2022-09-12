/*
** EPITECH PROJECT, 2022
** airplane
** File description:
** GameState
*/

#include "GameState.hpp"

GameState::GameState(sf::RenderWindow *target, sf::Font *font, std::shared_ptr<std::stack<State *>>  states) : State(target, font, states)
{
    _player = new Player();
}

GameState::~GameState()
{
    std::cout << "Ending GameState" << std::endl;
    delete _player;
}

void GameState::checkQuit()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        this->QuitState();
}

void GameState::update(const float &dt, sf::RenderTarget *target)
{
    this->checkQuit();
    _player->update(dt);
}

void GameState::onWindowResize(sf::RenderTarget *target)
{
}

void GameState::render(sf::RenderTarget *target)
{
    _player->render(target);
}

