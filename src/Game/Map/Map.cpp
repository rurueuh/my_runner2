/*
** EPITECH PROJECT, 2022
** my_runner2
** File description:
** Map
*/

#include "Map.hpp"

Map::Map()
{
    _texture.loadFromFile(_texturePath);
    for (int i = 30; i >= 0; i--) {
        std::vector<sf::Sprite> tmp;
        for (int j = 0; j < 1; j++) {
            sf::Sprite sprite;
            sprite.setTexture(_texture);
            sprite.setTextureRect(_spriteRect);
            sprite.setScale(1.025641025641026, 1);
            sprite.setPosition(i * _spriteRect.width, 1080 - _spriteRect.height);
            tmp.push_back(sprite);
        }
        _sprites.push_back(tmp);
    }
}

Map::~Map()
{
}

float Map::getMaxHeight(sf::Vector2f &posPlayer, sf::RenderWindow *window) const
{
    float yPlayer = posPlayer.y;
    for (auto &row : _sprites) {
        if (row[0].getPosition().x <= posPlayer.x && row[0].getPosition().x + row[0].getGlobalBounds().width >= posPlayer.x) {
            return row[row.size() - 1].getPosition().y;
        } else {
            continue;
        }
    }
    return window->getSize().y;
}

int Map::getBlockLengthMostFar()
{
    int length = 0;
    float max_x = 0;
    for (auto &row : _sprites) {
        if (row.size() == 0) {
            continue;
        }
        if (row.at(0).getPosition().x > max_x)
            length = row.size();
    }
    return length;
}

std::vector<sf::Sprite> Map::getLastRow()
{
    return _sprites[0];
}

std::vector<sf::Sprite> Map::getFirstRow()
{
    return _sprites[_sprites.size() - 1];
}

void Map::move(const float &dt, sf::RenderWindow *window)
{
    for (auto &row : _sprites) {
        for (auto &sprite : row) {
            sprite.move(-moveSpeed * dt, 0);
        }
    }
    auto Lrow = getLastRow();
    auto Frow = getFirstRow();
    if (Frow.at(0).getPosition().x + Frow.at(0).getGlobalBounds().width < 0) {
        _sprites.erase(_sprites.begin() + _sprites.size() - 1);
        int rand = std::rand() % 3 + 2;
        std::vector<sf::Sprite> tmp;
        for (int i = 0; i < rand; i++) {
            sf::Sprite sprite;
            sprite.setTexture(_texture);
            sprite.setTextureRect(_spriteRect);
            sprite.setScale(1.025641025641026, 1);
            sprite.setPosition(Lrow.at(0).getPosition().x + _spriteRect.width, 1080 - _spriteRect.height * i);
            tmp.push_back(sprite);
        }
        _sprites.insert(_sprites.begin(), tmp);
    }
}

void Map::update(const float &dt, sf::RenderWindow *window)
{
    move(dt, window);
}

void Map::render(sf::RenderTarget *target)
{
    for (auto &row : _sprites) {
        for (auto &sprite : row) {
            target->draw(sprite);
        }
    }
}
