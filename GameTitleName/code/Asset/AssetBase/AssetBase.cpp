#include<DxLib.h>

#include "AssetBase.h"

AssetBase::AssetBase()
    :holdHandle(-1)
    , dupHandle(-1)
    , assetType("")
    , jsonFile("")
{
    //�����Ȃ�
}

AssetBase::~AssetBase()
{
    //�����Ȃ�
}

void AssetBase::LoadJsonFile(std::string fileName)
{
    //�t�@�C���ǂݍ���
    std::ifstream ifs(fileName.c_str());

    //�t�@�C�����
    if (ifs.good())
    {
        rapidjson::IStreamWrapper isw(ifs);

        doc.ParseStream(isw);
    }
    ifs.close();

    //�A�Z�b�g�^�C�v�ݒ�
    rapidjson::Value::ConstMemberIterator type = doc.MemberBegin();
    assetType = type->name.GetString();
}

const int AssetBase::GetHandle(std::string handleName)
{
    //�擾�������n���h��������������Ԃ�
    auto iter = handle.find(handleName);
    if (iter != handle.end())
    {
        if (!CheckHandleASyncLoad(handle[handleName]))
        {
            return handle[handleName];
        }
    }

    //�Ԃ��Ȃ�������-1��Ԃ�
    return -1;
}