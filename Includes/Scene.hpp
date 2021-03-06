/*
** EPITECH PROJECT, 2022
** {FILENAME}
** File description:
** TODO
*/

#ifndef BOMBERMAN_SCENE_HPP
#define BOMBERMAN_SCENE_HPP

#include <vector>

#include "GameObject.hpp"
#include "GameCamera.hpp"
#include "GameSound.hpp"
#include "GamePlayer.hpp"
#include "GameText.hpp"
#include "GameScript.hpp"
#include "GameDrawMap.hpp"
#include "GameBomb.hpp"
#include "GameImage.hpp"
#include "GameButton.hpp"
#include "GameParticle.hpp"

namespace bomberman {
    class Scene {
    private:
        std::vector<GamePlayer *> PlayerQueue;
        std::vector<GamePlayer *> Players;
        std::vector<GameObject *> GameObjects;
        std::vector<GameSound *> GameSounds;
        std::vector<GameCamera *> GameCameras;
        std::vector<GameText *> GameTexts;
        std::vector<GameScript *> GameScripts;
        GameDrawMap *GameMap{};
        std::vector<GameImage *> GameImages;
        std::vector<GameButton *> GameButtons;
        std::vector<GamePowerUp *> GamePowerUps;
        ParticleSystem *pSystem{};

        bool CamSwitch{};
        bool Hover{};
    public:
        Scene() = default;

        virtual ~Scene() = default;

        void AddEntity(IEntity *entity);
        void StartScene();
        void DrawScene();
        void Draw3DAssets();
        void Draw2DAssets();
        void UnloadScene();
        void Start3D();
        void NextCamera();
        void MoveCamera();
        GameCamera *GetCamera(int i);
        GameText *GetText(int i);
        GamePlayer *GetPlayer(int i);
        void Populate(const std::vector<GamePlayer *> &newPlayers);
        GamePlayer *PopPlayer(GamePlayer *push = nullptr);
        void ChangePlayer(int i);
        std::vector<GameButton *> GetButtons();
        GameButton *GetButton(int i);
        GameDrawMap *GetMap();
        GameImage *GetImage(int i);
        GameScript *GetScript(int i);
        GamePowerUp *GetGamePowerUp(int i);
        GameObject *GetObject(int i);
        void SetCursor(bool hover);
        void SetActiveButton(ButtonType type,
                             bool active = true,
                             bool reset = false);
    };
}

#endif //BOMBERMAN_SCENE_HPP
