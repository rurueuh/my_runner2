/*
** EPITECH PROJECT, 2022
** airplane
** File description:
** Game
*/

#include "Game.hpp"

void Game::initWindow()
{
    this->_window = new sf::RenderWindow(sf::VideoMode(1920, 1080), TITLE, sf::Style::Fullscreen);
    this->_window->setFramerateLimit(144);
}

void Game::initStates()
{
    this->_states = std::make_shared<std::vector<State *>>();
    this->_states.get()->push_back(new LaunchState(this->_window, this->_font, _states));
}

Game::Game()
{
    this->initWindow();
    this->_font = new sf::Font();
    this->_font->loadFromFile("assets/font.ttf");
    this->initStates();
}

Game::~Game()
{
    delete this->_window;
    while (!this->_states.get()->empty()) {
        delete this->_states.get()->back();
        this->_states.get()->pop_back();
    }
    delete this->_font;
}

void Game::handleEvent()
{
    while (this->_window->pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed)
            this->_window->close();
        if (this->_event.type == sf::Event::KeyPressed && this->_event.key.code == sf::Keyboard::Escape)
            this->_window->close();
        if (this->_event.type == sf::Event::Resized)
            this->_states.get()->back()->onWindowResize(this->_window);
    }
}

static std::shared_ptr<std::vector<State *>> removeState(std::shared_ptr<std::vector<State *>> &states, State *state)
{
    std::vector<State *> *tmp = new std::vector<State *>();
    for (auto it = states.get()->begin(); it != states.get()->end(); it++) {
        if (*it != state)
            tmp->push_back(*it);
    }
    delete state;
    states = std::shared_ptr<std::vector<State *>>(tmp);
    return states;
}

void Game::update()
{
    this->updateDt();
    this->handleEvent();
    if (!this->_states.get()->empty()){
        this->_states.get()->back()->update(this->_deltaTime, this->_window);
        for (auto &state : *this->_states.get()) {
            if (state->getQuit()) {
                removeState(this->_states, state);
                sf::sleep(sf::milliseconds(400));
            }
        }
    } else {
        this->_window->close();
    }
}

void Game::render()
{
    this->_window->clear();

    // render items
    if (!this->_states.get()->empty())
        this->_states.get()->back()->render(this->_window);

    this->_window->display();
}

void Game::run()
{
    while (this->_window->isOpen()) {
        this->handleEvent();
        this->update();
        this->render();
    }
}
