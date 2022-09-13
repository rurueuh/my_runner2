/*
** EPITECH PROJECT, 2022
** airplane
** File description:
** GameState
*/

#include "GameState.hpp"

GameState::GameState(sf::RenderWindow *target, sf::Font *font, std::shared_ptr<std::vector<State *>> *states) : State(target, font, states)
{
    _map = new Map();
    _player = new Player(_map);
}

GameState::~GameState()
{
    std::cout << "Ending GameState" << std::endl;
    delete _player;
    delete _map;
}

void GameState::checkQuit()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        this->QuitState();
}

void GameState::update(const float &dt, sf::RenderTarget *target)
{
    this->checkQuit();


    _player->update(dt, dynamic_cast<sf::RenderWindow *>(target));
    if (_player->isPlayerDead() == true){
        this->QuitState();
        this->_states->get()->push_back(new DeadState(this->_target, this->_font, this->_states));
    }
    _map->update(dt, dynamic_cast<sf::RenderWindow *>(target));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        _player->jump();
}

void GameState::onWindowResize(sf::RenderTarget *target)
{
}

void GameState::render(sf::RenderTarget *target)
{
    _player->render(target);
    _map->render(target);
}

