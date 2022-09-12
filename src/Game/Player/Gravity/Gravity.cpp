/*
** EPITECH PROJECT, 2022
** my_runner2
** File description:
** Gravity
*/

#include "Gravity.hpp"

Gravity::Gravity(sf::Sprite *sprite)
{
    this->_sprite = sprite;
    this->_gravity = 0;
}

Gravity::~Gravity()
{
}

void Gravity::update(const float &dt)
{
    this->_gravity += GRAVITY_FORCE * dt;
    this->_sprite->move(0, this->_gravity);
}

void Gravity::setGravity(const float &gravity)
{
    this->_gravity = gravity;
}

