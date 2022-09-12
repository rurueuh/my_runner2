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

void Gravity::update(const float &dt, int height)
{
    if (this->_sprite->getPosition().y < height - this->_sprite->getGlobalBounds().height || (this->isGrounded == true && this->_gravity != 0)) {
        this->_gravity += Gravity::GRAVITY_FORCE * dt;
        this->_sprite->move(0, this->_gravity);
        this->isGrounded = false;
        std::cout << "not grounded" << std::endl;
    } else {
        if (this->isGrounded == false) {
            this->_gravity = 0;
            this->isGrounded = true;
            this->_sprite->setPosition(this->_sprite->getPosition().x, height - this->_sprite->getGlobalBounds().height);
        }
        std::cout << "grounded" << std::endl;
    }
}

void Gravity::setGravity(const float &gravity)
{
    this->_gravity = gravity;
}

