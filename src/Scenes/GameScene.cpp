/*
** EPITECH PROJECT, 2023
** FlappyBird
** File description:
** GameScene
*/

#include "GameScene.hpp"

void GameScene::loadScene(SceneManagerSystem &manager)
{
    Registry &registry = manager.getRegistry();
    RGraphic::IGraphic &graphic = manager.getGraphic();
    Entity background = registry.spawnEntity();
    Entity player = registry.spawnEntity();

    registry.addComponent<PositionComponent>(background, PositionComponent(1920 / 2, 1080 / 2));
    registry.addComponent<RectangleComponent>(background, RectangleComponent(Vector2D<double>(1920, 1080), {0, 190, 254, 255}));


    registry.addComponent<PlayerComponent>(player, PlayerComponent());
    registry.addComponent<PositionComponent>(player, PositionComponent(100, 100));
    registry.addComponent<LifeHitboxComponent>(player, LifeHitboxComponent(50, 50, 1));

    registry.addComponent<RectangleComponent>(player, RectangleComponent(Vector2D<double>(50, 50), {255, 0, 0, 255}));
}

void GameScene::run(SceneManagerSystem &manager)
{
}

void GameScene::unloadScene(SceneManagerSystem &manager)
{
}