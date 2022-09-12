/*
** EPITECH PROJECT, 2022
** my_runner2
** File description:
** Animation
*/

#include "Animation.hpp"

Animation::Animation(sf::Sprite *sprite)
{
    this->_sprite = sprite;
}

Animation::~Animation()
{
}

void Animation::update()
{
    int frame = this->_clock.getElapsedTime().asSeconds() / this->_frameTime;
    this->_sprite->setTextureRect(this->_frames[frame % this->_frames.size()]);
}
