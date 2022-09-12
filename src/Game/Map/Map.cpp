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
    for (int i = 0; i < 10; i++) {
        std::vector<sf::Sprite> tmp;
        for (int j = 0; j < 1; j++) {
            sf::Sprite sprite;
            sprite.setTexture(_texture);
            sprite.setTextureRect(_spriteRect);
            sprite.setPosition(i * 75, 1000);
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
    return 0;
}

void Map::update(const float &dt)
{
}

void Map::render(sf::RenderTarget *target)
{
    for (auto &row : _sprites) {
        for (auto &sprite : row) {
            target->draw(sprite);
        }
    }
}
