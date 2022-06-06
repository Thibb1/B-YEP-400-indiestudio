/*
** EPITECH PROJECT, 2022
** GameObject.cpp
** File description:
** TODO
*/

#include "GameObject.hpp"

namespace bomberman {
    GameObject::GameObject(const std::string &modelPath,
                           Vector3 position,
                           float scale,
                           Color tint)
            : position(position),
              startPosition(position),
              scale(scale),
              startScale(scale),
              tint(tint),
              startTint(tint),
              active(true) {

        model = LoadModel(modelPath.c_str());
    };

    GameObject::~GameObject() {
        UnloadModel(model);
    }

    void GameObject::Draw() {
        if (active)
            // DrawModel(model, position, scale, tint);
            DrawModelEx(model, position, Vector3{1.0f, 0.0f,0.0f}, -90.0f, Vector3{scale, scale, scale}, tint);
    }

    void GameObject::Reset() {
        ResetPosition();
        ResetScale();
        ResetTint();
        SetActive(true);
    }

    void GameObject::ResetPosition() {
        SetPosition(startPosition);
    }

    void GameObject::ResetScale() {
        scale = startScale;
    }

    void GameObject::ResetTint() {
        tint = startTint;
    }

    void GameObject::SetPosition(Vector3 newPosition) {
        position = newPosition;
    }

    void GameObject::SetActive(bool activate) {
        active = activate;
    }

    void GameObject::Move(Vector3 velocity) {
        position.x += velocity.x;
        position.y += velocity.y;
        position.z += velocity.z;
    }

    AnimatedGameObject::AnimatedGameObject(const std::string &modelPath,
                                           const std::string &texturePath,
                                           const std::string &animationPath,
                                           unsigned int animationCount)
            : GameObject(modelPath), animationNb(animationCount) {
        texture = LoadTexture(texturePath.c_str());
        SetMaterialTexture(&model.materials[0], MATERIAL_MAP_DIFFUSE, texture);
        animations = LoadModelAnimations(animationPath.c_str(), &animationNb);
    }

    AnimatedGameObject::~AnimatedGameObject() {
        std::cout << "Unloading model" << std::endl;
        for (unsigned int i = 0; i < animationNb; i++)
            UnloadModelAnimation(animations[i]);
        RL_FREE(animations);
        UnloadTexture(texture);
        UnloadModel(model);
    }

    void AnimatedGameObject::Update() {
        UpdateModelAnimation(model, animations[animationSelected], animationFrame);
        if (IsKeyDown(KEY_SPACE))
            animationFrame++;
        if (animationFrame >= animations[animationSelected].frameCount)
            animationFrame = 0;
        if (IsKeyDown(KEY_A)) {
            Move(Vector3 {0.01f, 0.0f, 0.0f});
        } else if (IsKeyDown(KEY_D)) {
            Move(Vector3 {-0.01f, 0.0f, 0.0f});
        } else if (IsKeyDown(KEY_W)) {
            Move(Vector3 {0.0f, 0.0f, 0.01f});
        } else if (IsKeyDown(KEY_S)) {
            Move(Vector3 {0.0f, 0.0f, -0.01f});
        } else if (IsKeyDown(KEY_Q)) {
            Move(Vector3 {0.0f, 0.01f, 0.0f});
        } else if (IsKeyDown(KEY_E)) {
            Move(Vector3 {0.0f, -0.01f, 0.0f});
        }
        if (IsKeyPressed(KEY_P)) {
            std::cout << position.x << "x " << position.y << "y "<< position.z << "z" << std::endl;
        }
    }

    void AnimatedGameObject::Reset() {
        ResetPosition();
        ResetScale();
        ResetTint();
        ResetAnimation();
        SetActive(true);
    }

    void AnimatedGameObject::ResetAnimation() {
        animationFrame = 0;
    }

    void AnimatedGameObject::SetAnimation(int newSelectedAnimation) {
        animationSelected = newSelectedAnimation;
        animationFrame = 0;
    }
}
