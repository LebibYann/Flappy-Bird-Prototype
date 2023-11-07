/*
** EPITECH PROJECT, 2023
** B-CPP-500-PAR-5-1-rtype-ethan.nguyen
** File description:
** main
*/

#include "FlappyBird.hpp"

int main(void)
{
    Registry registry;
    std::shared_ptr<RGraphic::IGraphic> sgraphic;
    sgraphic.reset(new RGraphic::SfmlGraphic());
    RGraphic::RInputs_t inputs;
    CheckboxSystem checkboxSystem(sgraphic);
    ButtonSystem buttonSystem(sgraphic);
    DropDownButtonSystem dropDownButtonSystem(sgraphic);
    SliderSystem sliderSystem(sgraphic);
    TextSystem textSystem(sgraphic);
    InputBoxSystem inputBoxSystem(sgraphic);
    TextureSystem textureSystem(sgraphic);
    RectangleSystem rectangleSystem(sgraphic);
    sgraphic->openWindow(1920, 1080, "Flappy Bird");
    SceneManagerSystem sceneManager(registry, sgraphic);
    PlayerMovementSystem playerSystem;

    registry.registerComponent<PositionComponent>(destroyPosition);
    registry.registerComponent<CheckboxComponent>(destroyCheckbox);
    registry.registerComponent<ButtonComponent>(destroyButton);
    registry.registerComponent<DropDownButtonComponent>(destroyDropDownButton);
    registry.registerComponent<SliderComponent>(destroySlider);
    registry.registerComponent<TextComponent>(destroyText);
    registry.registerComponent<InputBoxComponent>(destroyInputBox);
    registry.registerComponent<TextureComponent>(destroyTexture);
    registry.registerComponent<PositionComponent>(destroyInterpolation);
    registry.registerComponent<PlayerComponent>(destroyPlayer);
    registry.registerComponent<PipeComponent>(destroyPipe);
    registry.registerComponent<LifeHitboxComponent>(destroyLifeHitbox);
    registry.registerComponent<DamageHitboxComponent>(destroyDamageHitbox);
    registry.registerComponent<RectangleComponent>(destroyRectangle);

    registry.registerEvent<InputEvent>();

    registry.addEventListener(InputEventListener(sgraphic));

    registry.addSystem(StartFrameSystem(sgraphic));

    sceneManager.addScene("Game", GameScene());
    registry.addSystem<PositionComponent, PlayerComponent>(playerSystem);
    registry.addSystem<PositionComponent, RectangleComponent>(rectangleSystem);
    registry.addSystem<PositionComponent, TextureComponent>(textureSystem);
    registry.addSystem<PositionComponent, CheckboxComponent>(checkboxSystem);
    registry.addSystem<PositionComponent, ButtonComponent>(buttonSystem);
    registry.addSystem<PositionComponent, SliderComponent>(sliderSystem);
    registry.addSystem<PositionComponent, TextComponent>(textSystem);
    registry.addSystem<PositionComponent, InputBoxComponent>(inputBoxSystem);
    registry.addSystem<PositionComponent, DropDownButtonComponent>(dropDownButtonSystem);
    registry.addSystem(sceneManager);
    registry.addSystem(EndFrameSystem(sgraphic));

    sceneManager.changeScene(registry, "Game");

    registry.runLoop();
    sgraphic->closeWindow();
    return (0);
}
