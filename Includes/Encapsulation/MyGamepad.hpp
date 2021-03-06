/*
** EPITECH PROJECT, 2022
** MyGamepad.hpp
** File description:
** TODO
*/

#ifndef BOMBERMAN_MYGAMEPAD_HPP
#define BOMBERMAN_MYGAMEPAD_HPP

#include "raylib.h"

namespace bomberman {
    class MyGamepad {
    public:
        // Check if a key has been pressed once
        static bool isKeyPressed(int key);

        // Check if a key is being pressed
        static bool isKeyDown(int key);

        // Check if a gamepad is available
        static bool isGamepadAvailable(int gamepad);

        // Check if a gamepad button is being pressed
        static bool isGamepadButtonDown(int gamepad, int button);

        // Get axis movement value for a gamepad axis
        static float getGamepadAxisMovement(int gamepad, int axis);

        // Check if a gamepad button has been pressed once
        static bool isGamepadButtonPressed(int gamepad, int button);

        // Check if a mouse button has been pressed once
        static bool isMouseButtonPressed(int button);

        /// Get mouse position XY
        static Vector2 getMousePosition(void);
    };
}

#endif //BOMBERMAN_MYGAMEPAD_HPP
