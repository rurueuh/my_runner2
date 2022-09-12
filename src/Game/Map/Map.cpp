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
    for (int i = 0; i < 30; i++) {
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

void Map::move(const float &dt, sf::RenderWindow *window)
{
    for (auto &row : _sprites) {
        if (row.size() > 0) {
            if (row[0].getPosition().x + row[0].getGlobalBounds().width < 0) {
                row.clear();
                std::vector<sf::Sprite> tmp;
                int rand = std::rand() % 3 + 1;
                for (int j = 0; j < rand; j++) {
                    sf::Sprite sprite;
                    sprite.setTexture(_texture);
                    sprite.setTextureRect(_spriteRect);
                    sprite.setScale(1.025641025641026, 1);
                    sprite.setPosition(window->getSize().x, window->getSize().y - (j + 1) * _spriteRect.height);
                    tmp.push_back(sprite);
                }
                row = tmp;
            }
        }
        for (auto &sprite : row) {
            sprite.move(-moveSpeed * dt, 0);
        }
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
