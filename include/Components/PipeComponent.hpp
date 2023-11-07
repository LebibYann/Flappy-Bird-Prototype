/*
** EPITECH PROJECT, 2023
** FlappyBird
** File description:
** PipeComponent
*/

#pragma once

#include "GameEngine.hpp"

class PipeComponent : public IComponent{
    public:
        PipeComponent();
};

void destroyPipe(Registry &registry, Entity const &entity);