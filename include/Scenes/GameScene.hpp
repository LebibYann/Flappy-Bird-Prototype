/*
** EPITECH PROJECT, 2023
** FlappyBird
** File description:
** GameScene
*/

#pragma once

#include "IScene.hpp"
#include "SceneManagerSystem.hpp"
#include "GraphicEngine.hpp"
#include "PlayerComponent.hpp"
#include "RectangleComponent.hpp"

class GameScene : public IScene {
    public:
        void loadScene(SceneManagerSystem &manager);
        void run(SceneManagerSystem &manager);
        void unloadScene(SceneManagerSystem &manager);
};
