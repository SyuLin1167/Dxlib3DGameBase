#pragma once
#include<string.h>
#include<vector>

/// <summary>
/// �I�u�W�F�N�g�̃^�O
/// </summary>
static struct ObjectTag
{
    std::string CAMERA = "camera";
    std::string PLAYER = "player";
    std::string ENEMY = "enemy";
}ObjTag;

/// <summary>
/// ���[�v����p
/// </summary>
static std::vector <std::string> objTagAll{
    ObjTag.CAMERA,
    ObjTag.PLAYER,
    ObjTag.ENEMY,
};