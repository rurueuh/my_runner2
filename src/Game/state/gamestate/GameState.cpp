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
    _paralax = new Paralax(target->getSize());
    _score = new Score(font);
}

GameState::~GameState()
{
    std::cout << "Ending GameState" << std::endl;
    delete _player;
    delete _map;
    delete _paralax;
    delete _score;
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
    if (_player->isPlayerDead() == true) {
        this->QuitState();
        this->_states->get()->push_back(new DeadState(this->_target, this->_font, this->_states));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        _player->jump();

    _map->update(dt, dynamic_cast<sf::RenderWindow *>(target));
    _paralax->update(dt, target->getSize());
    _score->update();
}

void GameState::onWindowResize(sf::RenderTarget *target)
{
}

void GameState::render(sf::RenderTarget *target)
{
    _paralax->render(target);
    _map->render(target);
    _player->render(target);
    _score->render(target);
}

