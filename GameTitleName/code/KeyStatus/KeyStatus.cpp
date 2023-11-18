#include<DxLib.h>
#include "KeyStatus.h"

std::unique_ptr<KeyStatus> KeyStatus::singleton = nullptr;

void KeyStatus::InitKeyStatus()
{
    //���g�̒��g���󂾂�����C���X�^���X����
    if (!singleton)
    {
        singleton.reset(new KeyStatus);
    }
}

KeyStatus::KeyStatus()
{
    //�����Ȃ�
}

bool KeyStatus::KeyStateDecision(int key, int flag)
{
    //�L�[���i�[����Ă��Ȃ�������ۑ�
    auto findData = singleton->keyData.find(key);
    if (findData == singleton->keyData.end())
    {
        KeyParam keyParam = {};

        singleton->keyData.emplace(key, keyParam);
    }

    //�X�e�[�^�X�؂�ւ�
    ChangeKeyState(key);

    //���茋�ʂ�Ԃ�
    if (singleton->keyData[key].inputState & flag)
    {
        return true;
    }
    return false;
}

void KeyStatus::ChangeKeyState(int key)
{
    //�L�[���i�[����Ă���؂�ւ�����
    auto findData = singleton->keyData.find(key);
    if (findData != singleton->keyData.end())
    {
        auto& data = singleton->keyData[key];

        //�X�e�[�^�X�̐؂�ւ�������
        if (CheckHitKey(key))
        {
            //����������
            if (data.inputState & (UNINPUT | NOWUNINPUT))
            {
                data.inputState = ONINPUT;
                return;
            }
            data.inputState = NOWONINPUT;
        }
        else
        {
            //����������
            if (data.inputState & (ONINPUT | NOWONINPUT))
            {
                data.inputState = UNINPUT;
                return;
            }
            data.inputState = NOWUNINPUT;
        }
    }
}

KeyStatus::KeyParam::KeyParam()
    :inputState(UNINPUT)
{
    //�����Ȃ�
}

KeyStatus::~KeyStatus()
{
    //�f�[�^�̒��g������Ȃ�폜
    if (keyData.size() > 0)
    {
        keyData.clear();
    }
}