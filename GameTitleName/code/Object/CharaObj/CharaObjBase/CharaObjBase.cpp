#include "CharaObjBase.h"

using namespace math;

CharaObjBase::CharaObjBase(std::string tag)
    :ObjBase(tag)
    , isMove(false)
    , moveSpeed(0.0f)
    , nowRotate(false)
    , aimDir(VGet(0, 0, 0))
    , rotRad(0.0f)
    , rotYRad(math::DegToRad(-PI_RAD / 2))
{
    rotYMat = MGetRotY(rotYRad);
    rotateMat = MMult(MGetScale(objScale), rotYMat);
}

CharaObjBase::~CharaObjBase()
{
    //処理なし
}

void CharaObjBase::RotateYAxis(const VECTOR dir, float velocity)
{
    //現方向が目標方向でなければ回転中にする
    aimDir = dir;
    if (objDir != aimDir)
    {
        nowRotate = true;
    }

    //回転中なら
    if (nowRotate)
    {
        //目標方向付近まで回転
        if (VDot(objDir, aimDir) < SIMILAR_ANGLE )
        {
            //回転方向算出してベクトルと行列の両方を回転させる
            rotYRad += CalcRotDir(velocity);
            objDir = VTransform(objDir, rotYMat);
            rotateMat = MMult(MGetScale(objScale), MGetRotY(rotYRad));
        }
        else
        {
            //目標方向にして回転停止
            objDir = aimDir;
            nowRotate = false;
        }
    }
}

float CharaObjBase::CalcRotDir(float velocity)
{
    //ラジアン角にして回転行列へ変換
    rotRad = math::DegToRad(velocity);
    rotYMat = MGetRotY(rotRad);

    //回転方向を算出
    if (VCross(objDir, aimDir).y < 0)
    {
        rotYMat = MTranspose(rotYMat);
        return -rotRad;
    }
    return rotRad;
}

