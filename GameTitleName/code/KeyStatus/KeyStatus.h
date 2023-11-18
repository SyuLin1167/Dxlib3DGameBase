#pragma once
#include<unordered_map>
#include<memory>

constexpr int UNINPUT = 0x0001;     //�����͎�
constexpr int NOWUNINPUT = 0x0002;  //�����͒�
constexpr int ONINPUT = 0x0004;     //���͎�
constexpr int NOWONINPUT = 0x0008;  //���͒�

/// <summary>
/// KeyStatus�N���X
/// </summary>
class KeyStatus final
{
public:
    /// <summary>
    /// �L�[���͏���������
    /// </summary>
    static void InitKeyStatus();

    /// <summary>
    /// ���͔��菈��
    /// </summary>
    /// <param name="key">:���肵�����L�[</param>
    /// <param name="flag">:����t���O</param>
    /// <returns>�L�[�X�e�[�^�X���t���O�ƈ�v:true|�s��v:false</returns>
    static bool KeyStateDecision(int key,int flag);


    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~KeyStatus();
private:
    /// <summary>
    /// �R���X�g���N�^(�V���O���g��)
    /// </summary>
    KeyStatus();

    /// <summary>
    /// �L�[�p�����[�^�[
    /// </summary>
    struct KeyParam
    {
    public:
        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        KeyParam();

        int inputState;             //���̓X�e�[�^�X
    };

    /// <summary>
    /// �L�[�X�e�[�^�X�؂�ւ�����
    /// </summary>
    /// <param name="key">:�؂�ւ������L�[</param>
    static void ChangeKeyState(int key);

    static std::unique_ptr<KeyStatus> singleton;        //���g�̎���

    std::unordered_map<int ,KeyParam> keyData;          //�L�[�f�[�^
};

