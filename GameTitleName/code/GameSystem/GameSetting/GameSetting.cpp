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

    //���C�u����������
    assert(!DxLib_Init());

    AfterLibInit();
}

GameSetting::~GameSetting()
{
    //���C�u�����I��
    DxLib_End();
}

void GameSetting::BeforeLibInit()
{
    //�A���`�G�C���A�X��ݒ�
    SetFullSceneAntiAliasingMode(4, 2);

    // Direct3D9Ex ���g�p����
    SetUseDirect3DVersion(DX_DIRECT3D_9EX);
}

void GameSetting::AfterLibInit()
{
    //�`���𗠉�ʂɕύX
    SetDrawScreen(DX_SCREEN_BACK);

    //Z�o�b�t�@�ݒ�
    SetUseZBuffer3D(true);
    SetWriteZBuffer3D(true);
}