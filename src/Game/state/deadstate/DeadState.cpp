/*
** EPITECH PROJECT, 2022
** my_runner2
** File description:
** DeadState
*/

#include "DeadState.hpp"

DeadState::DeadState(sf::RenderWindow *window, sf::Font *font, std::shared_ptr<std::vector<State *>> states) : State(window, font, states)
{
    sf::Vector2f pos = {window->getSize().x / 2 - 60, window->getSize().y / 2};
    _text = new Text("You died", font, sf::Color::Red, pos, 40);
}

DeadState::~DeadState()
{
    std::cout << "Ending DeadState" << std::endl;
}

void DeadState::update(const float &dt, sf::RenderTarget *target)
{
    this->checkQuit();
}

void DeadState::render(sf::RenderTarget *target)
{
    _text->draw(target);
}

void DeadState::checkQuit()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        this->QuitState();
}
