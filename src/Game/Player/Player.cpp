/*
** EPITECH PROJECT, 2022
** my_runner2
** File description:
** Player
*/

#include "Player.hpp"

Player::Player()
{
    _texture.loadFromFile("assets/player.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(PLAYER_SPRITE_RECT);
    _sprite.setPosition(100, 100);
    // _gravity = new Gravity(&_sprite);
}

Player::~Player()
{
    // delete _gravity;
}

void Player::update(const float &dt)
{
    // _gravity->update(dt);
}

void Player::render(sf::RenderTarget *target)
{
    target->draw(_sprite);
}
