#pragma once
#include<DxLib.h>

namespace math
{
    /// <summary>
    /// �p�x���烉�W�A���ւ̕ϊ�����
    /// </summary>
    /// <param name="degre">:�p�x</param>
    /// <returns>�ϊ���̃��W�A���p</returns>
    template <typename T> float DegToRad(T degre)
    {
        return degre * DX_PI_F / 180.0f;
    }

    /// <summary>
    /// ���W�A������p�x�ւ̕ϊ�����
    /// </summary>
    /// <param name="rad">:</param>
    /// <returns>�ϊ���̊p�x</returns>
    template <typename T> float RadToDeg(T rad)
    {
        return rad * 180.0f / DX_PI_F;
    }


    /// <summary>
    /// �x�N�g���̑�������
    /// </summary>
    /// <param name="lhs">:���Ӄx�N�g��</param>
    /// <param name="rhs">:�E�Ӄx�N�g��</param>
    /// <returns>�x�N�g���̈�v:true|�s��v:false</returns>
    bool operator==(const VECTOR& lhs, const VECTOR& rhs);
};