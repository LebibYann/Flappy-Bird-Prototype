/*
** EPITECH PROJECT, 2023
** FlappyBird
** File description:
** PipeComponent
*/

#include "PipeComponent.hpp"

PipeComponent::PipeComponent()
{
}


void destroyPipe(Registry &registry, Entity const &entity)
{
    SparseArray<PipeComponent> &pipeArray = registry.getComponents<PipeComponent>();

    if (pipeArray.size() > entity)
        pipeArray[entity].reset();
}
