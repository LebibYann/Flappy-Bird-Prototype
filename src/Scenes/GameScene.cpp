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
    TextureComponent &backgroundTexture = *registry.addComponent<TextureComponent>(background, TextureComponent());
    TextureInfo sprite = TexturesGlobal::BANK[BIRDHOUSE_BACKGROUND];
    backgroundTexture.addTexture(BIRDHOUSE_BACKGROUND, graphic.loadTexture(sprite.path), sprite.dimension, sprite.nframes, 7569 / 1920);


    registry.addComponent<PlayerComponent>(player, PlayerComponent());
    registry.addComponent<PositionComponent>(player, PositionComponent(100, 100));
    registry.addComponent<LifeHitboxComponent>(player, LifeHitboxComponent(50, 50, 1));

    TextureComponent &playerTexture = *registry.addComponent<TextureComponent>(background, TextureComponent());
    sprite = TexturesGlobal::BANK[CUPHEAD_IDLE];
    playerTexture.addTexture(CUPHEAD_IDLE, graphic.loadTexture(sprite.path), sprite.dimension, sprite.nframes, 1);
    sprite = TexturesGlobal::BANK[CUPHEAD_DEAD];
    playerTexture.addTexture(CUPHEAD_DEAD, graphic.loadTexture(sprite.path), sprite.dimension, sprite.nframes, 1);
}

void GameScene::run(SceneManagerSystem &manager)
{
}

void GameScene::unloadScene(SceneManagerSystem &manager)
{
}