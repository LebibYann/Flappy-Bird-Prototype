/*
** EPITECH PROJECT, 2023
** RectangleComponent
** File description:
** RectangleComponent
*/

#pragma once

#include "GraphicEngine.hpp"

class RectangleComponent : public IComponent{
    public:
        RectangleComponent(Vector2D<double> size, RGraphic::RColor_t color);

        Vector2D<double> getSize() const;

        RGraphic::RColor_t getColor() const;
    private:
        Vector2D<double> _size;
        RGraphic::RColor_t _color;
};

void destroyRectangle(Registry &registry, Entity const &entity);