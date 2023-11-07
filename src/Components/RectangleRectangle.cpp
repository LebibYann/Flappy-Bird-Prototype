/*
** EPITECH PROJECT, 2023
** FlappyBird
** File description:
** RectangleComponent
*/

#include "RectangleComponent.hpp"

RectangleComponent::RectangleComponent(Vector2D<double> size, RGraphic::RColor_t color) : _size(size), _color(color)
{
}

Vector2D<double> RectangleComponent::getSize() const
{
    return (_size);
}

RGraphic::RColor_t RectangleComponent::getColor() const
{
    return (_color);
}

void destroyRectangle(Registry &registry, Entity const &entity)
{
    SparseArray<RectangleComponent> &rectangleArray = registry.getComponents<RectangleComponent>();

    if (rectangleArray.size() > entity)
        rectangleArray[entity].reset();
}
