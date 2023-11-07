/*
** EPITECH PROJECT, 2023
** FlappyBird
** File description:
** PlayerMovement
*/

#pragma once

#include "GraphicEngine.hpp"
#include "RectangleComponent.hpp"

class RectangleSystem : public ASystem {

  public:
    RectangleSystem(std::shared_ptr<RGraphic::IGraphic> &lib);

    void operator()(Registry &registry, SparseArray<PositionComponent> &positionsArray, SparseArray<RectangleComponent> &rectanglesArray);
  private:
    std::shared_ptr<RGraphic::IGraphic> &_lib;
};
