/*
** EPITECH PROJECT, 2022
** IEntity.hpp
** File description:
** TODO
*/

#ifndef BOMBERMAN_IENTITY_HPP
#define BOMBERMAN_IENTITY_HPP

#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <fstream>

#include "raylib.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#include "raymath.h"
#pragma GCC diagnostic pop

#include "Color.hpp"
#include "rlgl.h"
#include "Objects.hpp"
#include "Keyboard.hpp"
#include "Exception.hpp"
#include "Sound.hpp"
#include "Window.hpp"
#include "Load.hpp"
#include "Draw.hpp"
#include "MyGamepad.hpp"

namespace bomberman {
    class IEntity {
    public:
        virtual ~IEntity() = default;
    };
}
#endif //BOMBERMAN_IENTITY_HPP
