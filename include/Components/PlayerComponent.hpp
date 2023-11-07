/*
** EPITECH PROJECT, 2023
** PlayerComponent
** File description:
** PlayerComponent
*/

#pragma once

#include "GameEngine.hpp"

class PlayerComponent : public IComponent{
    public:
        PlayerComponent();
};

void destroyPlayer(Registry &registry, Entity const &entity);