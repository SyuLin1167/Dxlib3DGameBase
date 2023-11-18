#pragma once
#include<memory>
#include<vector>
#include<unordered_map>
#include<algorithm>

#include"../ObjBase/ObjBase.h"
#include"../ObjBase/ObjTag.h"

/// <summary>
/// �I�u�W�F�N�g�Ǘ�
/// </summary>
class ObjManager final
{
public:
    /// <summary>
    /// �I�u�W�F�N�g�}�l�[�W���[����������
    /// </summary>
    static void InitObjManager();

    /// <summary>
    /// �I�u�W�F�N�g�ǉ�����
    /// </summary>
    /// <param name="newObj">:�ǉ��I�u�W�F�N�g</param>
    static void AddObj(ObjBase* newObj);

    /// <summary>
    /// �I�u�W�F�N�g�X�V����
    /// </summary>
    /// <param name="deltaTime">:�f���^�^�C��</param>
    static void UpdateObj(const float deltaTime);

    /// <summary>
    /// �I�u�W�F�N�g�`��
    /// </summary>
    static void DrawObj();


    /// <summary>
    /// �S�I�u�W�F�N�g�폜����
    /// </summary>
    static void DeleteAllObj();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~ObjManager();

private:
    /// <summary>
    /// �R���X�g���N�^(�V���O���g��)
    /// </summary>
    ObjManager();

    /// <summary>
    /// �I�u�W�F�N�g���S����
    /// </summary>
    static void OnDeadObj();

    /// <summary>
    /// �I�u�W�F�N�g�폜����
    /// </summary>
    /// <param name="unnecObj">:�s�K�v�I�u�W�F�N�g</param>
    static void DeleteObj(std::shared_ptr<ObjBase> unnecObj);

    static std::unique_ptr<ObjManager> singleton;       //���g�̎���

    std::unordered_map<std::string, std::vector<
        std::shared_ptr<ObjBase>>> object;              //�I�u�W�F�N�g
};

