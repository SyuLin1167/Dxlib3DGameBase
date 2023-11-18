#include<DxLib.h>
#include<assert.h>

#include"../SceneBase/SceneBase.h"
#include"../../Object/ObjManager/ObjManager.h"
#include"../../Asset/AssetManager/AssetManager.h"
#include"../../FPS/FPS.h"
#include"../../KeyStatus/KeyStatus.h"
#include"../Title/Title.h"
#include "SceneManager.h"

SceneManager::SceneManager()
    :holdScene(nullptr)
    , fps(new FPS)
{
    ObjManager::InitObjManager();
    AssetManager::InitAssetManager();

    KeyStatus::InitKeyStatus();

    nowScene.emplace(new Title);
}

SceneManager::~SceneManager()
{
    //�����Ȃ�
}

void SceneManager::GameLoop()
{
    //�E�B���h�E��������܂Ń��[�v����
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //�V�[���̃t���[
        UpdateScene();
        ChangeScene();
        DrawScene();
    }
    ObjManager::DeleteAllObj();
}

void SceneManager::UpdateScene()
{
    //���݂̃V�[�����X�V����tmpScene�ɑ��
    fps->Update();
    holdScene=nowScene.top()->UpdateScene(fps->GetDeltaTime());
}

void SceneManager::DrawScene()
{
    //���݂̃V�[����`��
    ClearDrawScreen();
    nowScene.top()->DrawScene();
    ScreenFlip();
}

void SceneManager::ChangeScene()
{
    //nowScene��tmpScene�ƈقȂ��Ă����������đ��
    if (nowScene.top().get() != holdScene)
    {
        nowScene.pop();
        nowScene.emplace(holdScene);

        assert(!nowScene.empty());
    }
}