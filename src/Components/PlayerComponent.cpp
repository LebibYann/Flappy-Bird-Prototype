/*
** EPITECH PROJECT, 2023
** FlappyBird
** File description:
** PlayerComponent
*/

#include "PlayerComponent.hpp"

PlayerComponent::PlayerComponent()
{
}


void destroyPlayer(Registry &registry, Entity const &entity)
{
    SparseArray<PlayerComponent> &playerArray = registry.getComponents<PlayerComponent>();

    if (playerArray.size() > entity)
        playerArray[entity].reset();
}
