/*
** EPITECH PROJECT, 2023
** FlappyBird
** File description:
** PlayerMovementSystem
*/

#include "PlayerMovementSystem.hpp"

void PlayerMovementSystem::operator()(Registry &registry, SparseArray<PositionComponent> &positionsArray, SparseArray<PlayerComponent> &playersArray)
{
  Zipper<SparseArray<PlayerComponent>, SparseArray<PositionComponent>> players(playersArray, positionsArray);
  std::deque<InputEvent> inputsQueue = registry.getEvent<InputEvent>();
  
  RGraphic::RInputs_t inputs;
  if (inputsQueue.empty())
    return;
  inputs = inputsQueue.front().getInputs();
  registry.clearEvent<InputEvent>();
  for (auto it = players.begin(); it != players.end(); it++){
    PositionComponent &position = std::get<PositionComponent&>(*it);

    if (inputs.shoot)
      position.move(Vector2D<double>(0, -20));
    else
      position.move(Vector2D<double>(0, 5));
  }
}