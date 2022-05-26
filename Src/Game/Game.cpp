/*
** EPITECH PROJECT, 2022
** game.cpp
** File description:
** TODO
*/

#include "Game.hpp"

namespace bomberman {
    Game::Game::Game() {
        width = 1920;
        height = 1080;
        cam_angle = 0;
        cam_radius = 5;
        camera.position = Vector3 { -10.0f, 15.0f, -10.0f };
        camera.target = Vector3 { 0.0f, 0.0f, 0.0f };
        camera.up = Vector3 { 0.0f, 1.0f, 0.0f };
        camera.fovy = 20.0f;
        camera.projection = CAMERA_PERSPECTIVE;
    }

    Game::~Game() {
        CloseAudioDevice();
        CloseWindow();
    }

    void Game::createWindow() {
        InitWindow(width, height, "Indie Studio");
        rlDisableBackfaceCulling();
        SetConfigFlags(FLAG_MSAA_4X_HINT);
        InitAudioDevice();
        SetCameraMode(camera, CAMERA_ORBITAL);
        SetTargetFPS(60);
        scenes.LoadScenes();
    }

    void Game::run() {
        Shader shader = LoadShader(0, TextFormat("../Assets/Shaders/bloom.fs", 330));
        RenderTexture2D target = LoadRenderTexture(width, height);

        scenes.GetScene(0).StartScene();
        while (!WindowShouldClose()) {
            Scene currentScene = scenes.GetScene(0);
            UpdateCamera(&camera);
            BeginTextureMode(target);
            ClearBackground(BLACK);
            BeginMode3D(camera);
            DrawGrid(15, 1.0);
            currentScene.DrawScene();
            EndMode3D();
            EndTextureMode();
            BeginDrawing();
                ClearBackground(BLACK);
                if (IsKeyDown(KEY_B)) {
                    DrawTextureRec(target.texture, (Rectangle){ 0, 0, (float)target.texture.width, (float)-target.texture.height }, (Vector2){ 0, 0 }, WHITE);
                }
                else {
                    BeginShaderMode(shader);
                    DrawTextureRec(target.texture, (Rectangle){ 0, 0, (float)target.texture.width, (float)-target.texture.height }, (Vector2){ 0, 0 }, WHITE);
                    EndShaderMode();
                }
            EndDrawing();
        }
    }
}