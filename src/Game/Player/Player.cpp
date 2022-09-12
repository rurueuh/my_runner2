/*
** EPITECH PROJECT, 2022
** my_runner2
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(Map *map)
{
    _texture.loadFromFile("assets/player.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(PLAYER_SPRITE_RECT);
    _sprite.setPosition(100, 100);

    _gravity = new Gravity(&_sprite);
    _animation = new Animation(&_sprite);
    _map = map;
}

Player::~Player()
{
    delete _gravity;
    delete _animation;
}

void Player::jump()
{
    if (_gravity->getGrounded() == true)
        _gravity->setGravity(Gravity::JUMP);
}

void Player::update(const float &dt, sf::RenderWindow *window)
{
    sf::Vector2f posPlayer = _sprite.getPosition();
    _gravity->update(dt, _map->getMaxHeight(posPlayer, window));
    _animation->update();
}

void Player::render(sf::RenderTarget *target)
{
    target->draw(_sprite);
}
