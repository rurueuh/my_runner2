/*
** EPITECH PROJECT, 2022
** my_runner2
** File description:
** Score
*/

#include "Score.hpp"

Score::Score(sf::Font *font)
{
    this->_text = new Text("0", font, sf::Color::White);
}

Score::~Score()
{
    float score = this->_clock.getElapsedTime().asSeconds();
    // remplace in assets/score.txt the score if it's better
    std::fstream file;
    file.open("assets/score.txt", std::ios::in);
    std::string line;
    std::getline(file, line);
    file.close();
    if (line == "" || std::stof(line) < score){
        file.open("assets/score.txt", std::ios::out);
        file << score;
        file.close();
    }
    delete this->_text;
}

void Score::update()
{
    std::string str = std::to_string(this->_clock.getElapsedTime().asSeconds());
    this->_text->setString(str);
}

void Score::render(sf::RenderTarget *target)
{
    this->_text->draw(target);
}
