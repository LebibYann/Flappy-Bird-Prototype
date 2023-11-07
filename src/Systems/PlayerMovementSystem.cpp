/*
** EPITECH PROJECT, 2023
** FlappyBird
** File description:
** PlayerMovementSystem
*/

#include "PlayerMovementSystem.hpp"

void PlayerMovementSystem::operator()(Registry &registry, SparseArray<PlayerComponent> &playersArray, SparseArray<PositionComponent> &positionArray)
{
  Zipper<SparseArray<PlayerComponent>, SparseArray<PositionComponent>> players(playersArray, positionArray);
  std::deque<InputEvent> inputsQueue = registry.getEvent<InputEvent>();
  RGraphic::RInputs_t inputs = inputsQueue.front().getInputs();

  registry.clearEvent<InputEvent>();
  for (auto player : players){
    PositionComponent &position = std::get<PositionComponent&>(player);

    if (inputs.shoot)
      position.move(Vector2D<double>(0, -20));
    else
      position.move(Vector2D<double>(0, 5));
  }
}