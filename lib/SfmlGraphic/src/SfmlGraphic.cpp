/*
** EPITECH PROJECT, 2023
** B-CPP-500-PAR-5-1-rtype-ethan.nguyen
** File description:
** SfmlGraphic
*/

#include "SfmlGraphic.hpp"

RGraphic::SfmlGraphic::SfmlGraphic()
{
}

RGraphic::SfmlGraphic::~SfmlGraphic()
{
    this->closeWindow();
}

void RGraphic::SfmlGraphic::openWindow(std::size_t width, std::size_t height, std::string name)
{
    if (!this->_window.isOpen()) {
        this->_window.create(sf::VideoMode(width, height), name.c_str());
    }
}

void RGraphic::SfmlGraphic::toggleFullscreen(bool fullscreen, int selectedResolution, std::string name)
{
}

void RGraphic::SfmlGraphic::setFps(int fps)
{
}

void RGraphic::SfmlGraphic::setVolume(double volume)
{
}

bool RGraphic::SfmlGraphic::windowShouldClose()
{
    if (!this->_window.isOpen())
        return (true);
    this->_window.pollEvent(this->_event);
    return (this->_event.type == sf::Event::Closed);
}

void RGraphic::SfmlGraphic::closeWindow()
{
    this->_window.close();
}

void RGraphic::SfmlGraphic::startFrame()
{
    this->_window.clear(sf::Color(0, 0, 0, 255));
}

void RGraphic::SfmlGraphic::endFrame()
{
    this->_window.display();
}

void RGraphic::SfmlGraphic::drawText(RVect2_t position, std::string text, uint16_t fontSize, uint16_t outlineSize, RColor_t color, RColor_t outlineColor)
{
}

void RGraphic::SfmlGraphic::drawRectangle(RRectangle_t rectangle, RColor_t color)
{
    sf::RectangleShape sqr;
    sf::Vector2f pos;

    sqr.setFillColor(sf::Color(color.r, color.g, color.b, color.a));
    sqr.setPosition(sf::Vector2f(rectangle.x, rectangle.y));
    sqr.setSize(sf::Vector2f(rectangle.width, rectangle.height));
    this->_window.draw(sqr);
}

void RGraphic::SfmlGraphic::drawCheckbox(RRectangle_t rectangle, std::string text, bool &checked)
{
}

void RGraphic::SfmlGraphic::drawInputBox(RRectangle_t rectangle, char *text, uint16_t maxBuf, bool &editMode)
{
}

void RGraphic::SfmlGraphic::drawButton(RRectangle_t rectangle, std::string text, bool shown, std::function<void()> onClick)
{
}

void RGraphic::SfmlGraphic::drawDropDownButton(RRectangle_t rectangle, std::string text, int &activeMode, bool &editMode)
{
}

void RGraphic::SfmlGraphic::drawSlider(RRectangle_t rectangle, std::string textLeft, std::string textRight, double &value)
{
}

void RGraphic::SfmlGraphic::drawTexture(RGraphic::RTexture rtexture, RRectangle_t source, RRectangle_t dest, double rotation)
{
}

RGraphic::RTexture RGraphic::SfmlGraphic::loadTexture(std::string path)
{
}

void RGraphic::SfmlGraphic::loadFont(std::string path)
{
}

RGraphic::RMusic RGraphic::SfmlGraphic::loadMusic(std::string path)
{
}

void RGraphic::SfmlGraphic::playMusic(RGraphic::RMusic rmusic)
{
}

void RGraphic::SfmlGraphic::updateMusic(RGraphic::RMusic rmusic)
{
}

void RGraphic::SfmlGraphic::unloadMusic(RGraphic::RMusic rmusic)
{
}

RGraphic::RInputs_t RGraphic::SfmlGraphic::getInputs()
{
    RGraphic::RInputs_t inputs;

    this->_window.pollEvent(this->_event);
    inputs.down =  sf::Keyboard::isKeyPressed(sf::Keyboard::S);
    inputs.up = sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
    inputs.left = sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
    inputs.right = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    inputs.shoot = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
    inputs.pause = sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
    return (inputs);
}
