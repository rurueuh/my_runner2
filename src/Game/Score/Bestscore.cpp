/*
** EPITECH PROJECT, 2022
** my_runner2
** File description:
** Bestscore
*/

#include "Bestscore.hpp"

Bestscore::Bestscore(sf::Font *font, sf::Vector2f pos)
{
    std::string message = "Best score : ";
    std::fstream file;
    file.open("assets/score.txt", std::ios::in);
    std::string line;
    std::getline(file, line);
    file.close();
    if (line != "")
        message += line;
    else
        message += "0";
    this->_text = new Text(message, font, sf::Color::White, pos);
}

Bestscore::~Bestscore()
{
    delete this->_text;
}

void Bestscore::render(sf::RenderTarget *target)
{
    this->_text->draw(target);
}