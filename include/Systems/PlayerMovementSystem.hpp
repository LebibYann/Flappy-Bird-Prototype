/*
** EPITECH PROJECT, 2023
** FlappyBird
** File description:
** PlayerMovement
*/

#pragma once

#include "GraphicEngine.hpp"
#include "PlayerComponent.hpp"

class PlayerMovementSystem : public ASystem {

  public:
    void operator()(Registry &registry, SparseArray<PlayerComponent> &playersArray, SparseArray<PositionComponent> &positionArray);
};
