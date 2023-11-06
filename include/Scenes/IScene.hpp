/*
** EPITECH PROJECT, 2023
** B-CPP-500-PAR-5-1-rtype-ethan.nguyen
** File description:
** IScene
*/

#pragma once

class SceneManagerSystem;

class IScene {
    public:
        ~IScene() = default;

        virtual void loadScene(SceneManagerSystem &manager) = 0;
        virtual void run(SceneManagerSystem &manager) = 0;
        virtual void unloadScene(SceneManagerSystem &manager) = 0;
};
