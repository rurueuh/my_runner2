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

bool Gravity::isInBlock(int height1, int height2, sf::Sprite &sprite)
{
    if (sprite.getPosition().y + sprite.getGlobalBounds().height > height1 + 30 || sprite.getPosition().y + sprite.getGlobalBounds().height > height2 + 30)
        return true;
    return false;
}

void Gravity::update(const float &dt, int height1, int height2)
{
    if (this->_sprite->getPosition().y < height1 - this->_sprite->getGlobalBounds().height
    &&  this->_sprite->getPosition().y < height2 - this->_sprite->getGlobalBounds().height
    || (this->isGrounded == true && this->_gravity != 0)) {
        this->_gravity += Gravity::GRAVITY_FORCE * dt;
        this->_sprite->move(0, this->_gravity);
        this->isGrounded = false;
    } else {
        if (this->isGrounded == false) {
            this->_gravity = 0;
            this->isGrounded = true;
            this->_sprite->setPosition(this->_sprite->getPosition().x, (height1 < height2 ? height1 : height2) - this->_sprite->getGlobalBounds().height);
        }
    }
}

void Gravity::setGravity(const float &gravity)
{
    this->_gravity = gravity;
}

