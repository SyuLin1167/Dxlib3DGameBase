#include<DxLib.h>
#include<assert.h>

#include "GameSetting.h"

std::unique_ptr<GameSetting> GameSetting::singleton = nullptr;

void GameSetting::Init()
{
    if (!singleton)
    {
        singleton.reset(new GameSetting);
    }
}

GameSetting::GameSetting()
{
    BeforeLibInit();

    //ライブラリ初期化
    assert(!DxLib_Init());

    AfterLibInit();
}

GameSetting::~GameSetting()
{
    //ライブラリ終了
    DxLib_End();
}

void GameSetting::BeforeLibInit()
{
    //アンチエイリアスを設定
    SetFullSceneAntiAliasingMode(4, 2);

    // Direct3D9Ex を使用する
    SetUseDirect3DVersion(DX_DIRECT3D_9EX);
}

void GameSetting::AfterLibInit()
{
    //描画先を裏画面に変更
    SetDrawScreen(DX_SCREEN_BACK);

    //Zバッファ設定
    SetUseZBuffer3D(true);
    SetWriteZBuffer3D(true);
}