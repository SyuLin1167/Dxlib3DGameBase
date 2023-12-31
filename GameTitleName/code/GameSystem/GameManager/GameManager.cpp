#include"../Window/Window.h"
#include"../GameSetting/GameSetting.h"
#include"../../Scene/SceneManager/SceneManager.h"

#include "GameManager.h"

GameManager::GameManager()
{
    //ログの非表示
    SetOutApplicationLogValidFlag(false);

    //初期化処理
    Window::Init();
    GameSetting::Init();
    sceneManager.reset(new SceneManager);
}

GameManager::~GameManager()
{
    //処理なし
}

void GameManager::Procces()
{
    sceneManager->GameLoop();
}