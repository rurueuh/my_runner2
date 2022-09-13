/*
** EPITECH PROJECT, 2022
** my_runner2
** File description:
** Paralax
*/

#include "Paralax.hpp"

Paralax::Paralax(sf::Vector2u size_window)
{
    for (int i = 0; i < PARALAX_NB; i++) {
        _paralax[i].texture.loadFromFile(_path[i]);
        _paralax[i].texture.setRepeated(true);
        _paralax[i].sprite.setTexture(_paralax[i].texture);
        _paralax[i].sprite.setPosition(0, 0);
        _paralax[i].sprite.setScale(size_window.x / _paralax[i].sprite.getGlobalBounds().width, size_window.y / _paralax[i].sprite.getGlobalBounds().height);
        _paralax[i].sprite.setTextureRect(sf::IntRect(0, 0, _paralax[i].sprite.getGlobalBounds().width * 2, _paralax[i].sprite.getGlobalBounds().height * 2));
        _paralax[i].speed = sf::Vector2f(PARALAX_SPEED * (i + 1), 0);
    }
}

Paralax::~Paralax()
{
}

void Paralax::update(const float &dt, sf::Vector2u size)
{
    for (int i = 0; i < PARALAX_NB; i++) {
        _paralax[i].sprite.move(-_paralax[i].speed * dt);
        std::cout << _paralax[i].sprite.getPosition().x << std::endl;
        if (_paralax[i].sprite.getPosition().x > -size.x * 2)
            _paralax[i].sprite.setPosition(1920, 0);
    }
}
void Paralax::render(sf::RenderTarget *target)
{
    for (int i = 0; i < PARALAX_NB; i++)
        target->draw(_paralax[i].sprite);
}
