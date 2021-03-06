/*
** EPITECH PROJECT, 2022
** GameText.cpp
** File description:
** GameText
*/

#include "GameText.hpp"

namespace bomberman {
    GameText::GameText(const std::string &font, const std::string &msg, float x, float y, float fontSize, MyColor color, bool flash) {
        _fontSize = fontSize;
        _font = Load::loadFontEx(font.c_str(), (int)_fontSize, nullptr, 250);
        _msg = msg;
        _fontPosition.x = x;
        _fontPosition.y = y;
        _color = color;
        _flash = flash;
        _framesCounter = 0;
        active = true;
        if (!std::ifstream(font).good())
            throw BuildError("Failed to load font " + font, __FILE__, __LINE__);
    }

    void GameText::Draw() {
        if (!active)
            return;
        if (!_flash)
            Draw::drawTextEx(_font, _msg.c_str(), _fontPosition, _fontSize, 0, _color);
        else {
            if (((_framesCounter / 30) % 2)) 
                Draw::drawTextEx(_font, _msg.c_str(), _fontPosition, _fontSize, 0, _color);
        }
    }

    void GameText::Update() {
        if (active)
            _framesCounter++;
    }

    void GameText::SetActive(bool activate) {
        active = activate;
    }
}
