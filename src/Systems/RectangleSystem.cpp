/*
** EPITECH PROJECT, 2023
** FlappyBird
** File description:
** PlayerMovementSystem
*/

#include "RectangleSystem.hpp"

RectangleSystem::RectangleSystem(std::shared_ptr<RGraphic::IGraphic> &lib) : _lib(lib)
{
}

void RectangleSystem::operator()(Registry &registry, SparseArray<PositionComponent> &positionArray, SparseArray<RectangleComponent> &rectangleArray)
{
  Zipper<SparseArray<PositionComponent>, SparseArray<RectangleComponent>> players(positionArray, rectangleArray);

  for (auto player : players){
    Vector2D<double> position = std::get<PositionComponent&>(player).getPosition();
    Vector2D<double> size = std::get<RectangleComponent&>(player).getSize();
    RGraphic::RColor_t color = std::get<RectangleComponent&>(player).getColor();

    _lib->drawRectangle({position._x, position._y, size._x, size._y}, color);
  }
}