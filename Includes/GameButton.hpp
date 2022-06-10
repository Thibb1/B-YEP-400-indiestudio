/*
** EPITECH PROJECT, 2022
** GameButton.hpp
** File description:
** TODO
*/
#ifndef BOMBERMAN_GAMEBUTTON_HPP
#define BOMBERMAN_GAMEBUTTON_HPP

#include "IEntity.hpp"

namespace bomberman {
    typedef enum {
        BUTTON_MENU = 0, BUTTON_SELECT, BUTTON_GAME, BUTTON_SETTINGS
    } ButtonType;

    class GameButton : public IEntity {
    private:
        bool active;
        bool state;
        Texture onTexture{};
        Texture offTexture{};
        int posX;
        int posY;
        int type;
        Rectangle collision{};
        Color tint{};
    public:
        GameButton(int x,
                   int y,
                   const std::string &onPath,
                   const std::string &offPath,
                   int type = BUTTON_MENU);

        GameButton(int x,
                   int y,
                   const std::string &onPath,
                   int type = BUTTON_MENU)
                : GameButton(x, y, onPath, onPath, type) {
        }

        ~GameButton() override;

        void Update();

        void Draw();

        void SetActive(bool activated);

        void SetState(bool newState);

        bool GetState() const;

        int GetType() const;
    };
}
#endif //BOMBERMAN_GAMEBUTTON_HPP
