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
}

void RGraphic::SfmlGraphic::openWindow(std::size_t width, std::size_t height, std::string name)
{
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
}

void RGraphic::SfmlGraphic::closeWindow()
{
}

void RGraphic::SfmlGraphic::startFrame()
{
}

void RGraphic::SfmlGraphic::endFrame()
{
}

void RGraphic::SfmlGraphic::drawText(RVect2_t position, std::string text, uint16_t fontSize, uint16_t outlineSize, RColor_t color, RColor_t outlineColor)
{
}

void RGraphic::SfmlGraphic::drawRectangle(RRectangle_t rectangle, RColor_t color)
{
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
}
