/*
** EPITECH PROJECT, 2022
** GamePlayer.hpp
** File description:
** TODO
*/

#ifndef BOMBERMAN_GAMEPLAYER_HPP
#define BOMBERMAN_GAMEPLAYER_HPP

#include "GameObject.hpp"
#include "GameBomb.hpp"
#include "GameDrawMap.hpp"
#include "GameSound.hpp"
#include "Gamepad.hpp"

namespace bomberman {

    class GamePlayer : public AnimatedGameObject {
    private:
        bool canPlay{};
        std::vector<GameBomb *> bombs;
        GameDrawMap *map{};
        Sound step{};
        Sound dead{};
        Sound place{};
        Sound levelUp{};
        int fireUp;
        int lives;
        int maxBombsStat;
        float speed;
        tPoint now;
        tPoint previous;
        double elapsed{};
        double wallPass{};
        bool cpu = true;
        int direction{};
        Keyboard *keys = nullptr;
        Gamepad *gamepad = nullptr;
    public:
        GamePlayer(const std::string &modelPath,
                   const std::string &texturePath,
                   const std::string &animationPath,
                   float scale = 1.0f,
                   unsigned int animationCount = 1)
                : AnimatedGameObject(modelPath, texturePath, animationPath, animationCount, scale),
                  step(LoadSound("../Assets/Bomb/step.mp3")),
                  dead(LoadSound("../Assets/Bomb/squish.mp3")),
                  place(LoadSound("../Assets/Bomb/place.mp3")),
                  levelUp(LoadSound("../Assets/Bomb/up.mp3")),
                  fireUp(3),
                  lives(1),
                  maxBombsStat(1),
                  speed(2.f),
                  previous(std::chrono::system_clock::now()) {
        }

        GamePlayer(const std::string &modelPath,
                   const std::string &texturePath,
                   float scale = 1.0f,
                   unsigned int animationCount = 1)
                : GamePlayer(modelPath, texturePath, modelPath, scale, animationCount) {
        }

        void Update() override;
        void SetPlay(bool play);
        void SetKeys(KeysLayout playerNB);
        void SetKeys(int playerNB);
    
        void SetGamepad(Gamepad *gp);
    
        Gamepad *GetGamepad();

        std::vector<GameBomb *> GetBombs();
        void RemoveLive();
        void SetMap(GameDrawMap *newMap);
        bool isCpu();
        void switchPlayer();
        void setCpu(bool nv);
        void Move(MyVector3 velocity) override;
        void SavePlayer(int i);
        void LoadPlayer(int i);
        void SetActive(bool activate) override;
        void AddBomb();

        void GetPowerUp(char block);
        [[nodiscard]] int GetMaxBombs() const;
        [[nodiscard]] float GetSpeed() const;
        [[nodiscard]] int GetFireUps() const;
        [[nodiscard]] float GetWall() const;

        void Reset() override;
        void CPUPlay();
    };
}

#endif //BOMBERMAN_GAMEPLAYER_HPP
