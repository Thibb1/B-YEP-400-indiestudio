/*
** EPITECH PROJECT, 2022
** SceneManager.cpp
** File description:
** TODO
*/

#include "SceneManager.hpp"
#include "Game.hpp"

namespace bomberman {
    SceneManager::SceneManager(Game *pGame) {
        gameRef = pGame;
        CreateMenuScene();
        CreateLevelScene();
        CreateUiScene();
        CreateSettingsScene();
        CreateHowToPlayScene();
    }

    void SceneManager::CreateMenuScene() {
        auto *menu = new Scene;
        menu->AddEntity(new GameCamera());
        menu->GetCamera(0)->SetMode(CAMERA_ORBITAL);
        menu->AddEntity(new GameCamera(MyVector3{-1.7f, 0.5f, -1.1f},
                                       MyVector3{0.0f, 0.0f, 0.0f},
                                       MyVector3{0.0f, 1.0f, 0.0f},
                                       32.0f,
                                       CAMERA_PERSPECTIVE));
        menu->AddEntity(new GameObject("../Assets/Level/forest.obj"));
        menu->AddEntity(new GameSound("../Assets/Songs/ForestSong.mp3", true));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Fox.iqm",
                                       "../Assets/AnimalsCharacters/TexFox.png",
                                       0.1f));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Pig.iqm",
                                       "../Assets/AnimalsCharacters/TexPig.png",
                                       0.1f));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Pigeon.iqm",
                                       "../Assets/AnimalsCharacters/TexPigeon.png",
                                       0.1f));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Toucan.iqm",
                                       "../Assets/AnimalsCharacters/TexToucan.png",
                                       0.1f));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Fox.iqm",
                                       "../Assets/AnimalsCharacters/TexWolf.png",
                                       0.1f));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Cat.iqm",
                                       "../Assets/AnimalsCharacters/TexCat.png",
                                       0.1f));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Owl.iqm",
                                       "../Assets/AnimalsCharacters/TexOwl.png",
                                       0.1f));
        menu->AddEntity(new GamePlayer("../Assets/AnimalsCharacters/Gazelle.iqm",
                                       "../Assets/AnimalsCharacters/TexGazelle.png",
                                       "../Assets/AnimalsCharacters/Gazelle.iqm",
                                       0.1f));
        menu->AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "Forest Bomberman", 525, 100, 200, WHITE));
        menu->AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "Press Enter To Play", 625, 400, 125, WHITE, true));
        menu->AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "Select players", 645, 100, 200, WHITE));
        menu->AddEntity(new GameButton(1750, 950, "../Assets/Buttons/howtoplay.png"));
        menu->AddEntity(new GameButton(450, 750, "../Assets/Buttons/rightOn.png", BUTTON_SELECT));
        menu->AddEntity(new GameButton(800, 750, "../Assets/Buttons/rightOn.png", BUTTON_SELECT));
        menu->AddEntity(new GameButton(1400, 750, "../Assets/Buttons/rightOn.png", BUTTON_SELECT));
        menu->AddEntity(new GameButton(1700, 750, "../Assets/Buttons/rightOn.png", BUTTON_SELECT));
        menu->GetText(2)->SetActive(false);
        menu->AddEntity(new GameScript(gameRef, 1));
        menu->StartScene();
        scenes.push_back(menu);
    }

    void SceneManager::CreateLevelScene() {
        auto *level = new Scene;
        level->AddEntity(new GameCamera(MyVector3{0.0f, 22.0f, -12.0f},
                                       MyVector3{0.0f, 0.0f, 0.0f},
                                       MyVector3{0.0f, 1.0f, 0.0f},
                                       50.0f,
                                       CAMERA_PERSPECTIVE));
        level->AddEntity(new GameSound("../Assets/Songs/CoffeeSong.mp3", true));
        level->AddEntity(new GameDrawMap("../Assets/Texture/brick.png", "../Assets/Texture/wood.png", WHITE));
        level->AddEntity(new GameText("../Assets/Font/Beauty_Forest.free.ttf", "Level 1", 875, 80, 125, WHITE));
        for (int y = 0; y < 2; y++) {
            for (int x = 0; x < 3; x++) {
                level->AddEntity(new GameImage("../Assets/Heart/little_life.png", 10 + 100 * x, 100 + 800 * y));
                level->AddEntity(new GameImage("../Assets/Heart/little_life.png", 1610 + 100 * x, 100 + 800 * y));
            }
        }
        scenes.push_back(level);
    }

    void SceneManager::CreateUiScene() {
        auto *ui = new Scene;
        ui->AddEntity(new GameButton(1750, 10, "../Assets/Buttons/settings.png"));
        scenes.push_back(ui);
    }

    void SceneManager::CreateSettingsScene() {
        auto *settings = new Scene;
        settings->AddEntity(new GameImage("../Assets/UI/text_box.png", 500, 200));
        settings->AddEntity(new GameButton(850, 500, "../Assets/Buttons/darkmode.png", "../Assets/Buttons/lightmode.png"));
        settings->AddEntity(new GameButton(1220, 770, "../Assets/UI/close_button90.png"));
        scenes.push_back(settings);
    }

    void SceneManager::CreateHowToPlayScene() {
        auto *howToPlay = new Scene;
        howToPlay->AddEntity(new GameImage("../Assets/UI/how_to_play.png", 550, 280));
        howToPlay->AddEntity(new GameButton(1220, 770, "../Assets/UI/close_button90.png"));
        scenes.push_back(howToPlay);
    }

    Scene *SceneManager::GetScene(int sceneId) {
        return scenes.at(sceneId);
    }
}
