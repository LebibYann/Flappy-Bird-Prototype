/*
** EPITECH PROJECT, 2023
** B-CPP-500-PAR-5-1-rtype-ethan.nguyen
** File description:
** SceneManager
*/

#pragma once

#include <any>
#include <unordered_map>
#include <string>
#include <iostream>
#include <memory>
#include <optional>

#include "IGraphic.hpp"
#include "GraphicEngine.hpp"
#include "IScene.hpp"
#include "ASystem.hpp"

class SceneManagerSystem : public ASystem {

  public:
        SceneManagerSystem(Registry &registry, std::shared_ptr<RGraphic::IGraphic> lib);
        ~SceneManagerSystem();

        void operator()(Registry &registry);

        template<typename Scene>
        void addScene(std::string sceneName, Scene &&scene, std::any sceneData = {})
        {
            if (sceneNameExist(sceneName))
                return;
            auto &newScene = _sceneList[sceneName];
            newScene.first = std::make_unique<Scene>(std::forward<Scene>(scene));
            newScene.second = sceneData;
        }

        IScene &getScene(const std::string &sceneName);

        void changeScene(Registry &registry, const std::string &sceneName);

        bool sceneNameExist(const std::string &sceneName);

        RGraphic::RMusic &getMusicTheme(void);

        RGraphic::IGraphic &getGraphic(void) {
            return (*(this->_lib.get()));
        }

        Registry &getRegistry(void) {
            return (this->_registry);
        }

private:
    Registry &_registry;
    std::shared_ptr<RGraphic::IGraphic> _lib;
    std::string _currentScene;
    RGraphic::RMusic _musicTheme;
    std::unordered_map<std::string, std::pair<std::unique_ptr<IScene>, std::optional<std::any>>> _sceneList;
};
