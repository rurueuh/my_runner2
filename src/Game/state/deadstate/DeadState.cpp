/*
** EPITECH PROJECT, 2022
** my_runner2
** File description:
** DeadState
*/

#include "DeadState.hpp"
#include "LaunchState.hpp"
#include "GameState.hpp"

DeadState::DeadState(sf::RenderWindow *window, sf::Font *font, std::shared_ptr<std::vector<State *>> *states) : State(window, font, states)
{
    sf::Vector2f pos = {window->getSize().x / 2 - (float) 60, (float) window->getSize().y / 2};
    _text = new Text("You died", font, sf::Color::Red, pos, 40);
    _button_to_menu = std::make_pair(new Button(0, 0, 200, 50, "go to menu", font, 32, sf::Color(150, 150, 150), sf::Color::Red, sf::Color::Blue), &DeadState::buttonToMenu);
    _button_restart = std::make_pair(new Button(0, 200, 200, 50, "restart", font, 32, sf::Color(150, 150, 150), sf::Color::Red, sf::Color::Blue), &DeadState::buttonRestart);

    _score = new Bestscore(font, sf::Vector2f(pos.x, pos.y + 100));
}

DeadState::~DeadState()
{
    delete _score;
    delete _text;
    delete _button_to_menu.first;
    delete _button_restart.first;
    std::cout << "Ending DeadState" << std::endl;
}

void DeadState::buttonRestart()
{
    this->QuitState();
    this->_states->get()->push_back(new GameState(this->_target, this->_font, this->_states));
}

void DeadState::buttonToMenu()
{
    this->QuitState();
}

void DeadState::update(const float &dt, sf::RenderTarget *target)
{
    this->checkQuit();
    this->_button_to_menu.first->update(sf::Vector2f(target->mapCoordsToPixel((sf::Vector2f) sf::Mouse::getPosition(*dynamic_cast<sf::Window *>(target)))));
    this->_button_restart.first->update(sf::Vector2f(target->mapCoordsToPixel((sf::Vector2f) sf::Mouse::getPosition(*dynamic_cast<sf::Window *>(target)))));
    if (_button_to_menu.first->isPressed() == true)
        (this->*_button_to_menu.second)();
    if (_button_restart.first->isPressed() == true)
        (this->*_button_restart.second)();
}

void DeadState::render(sf::RenderTarget *target)
{
    _text->draw(target);
    _score->render(target);
    _button_to_menu.first->draw(target);
    _button_restart.first->draw(target);
}

void DeadState::checkQuit()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        this->QuitState();
}
