#include<assert.h>

#include "ObjManager.h"

std::unique_ptr<ObjManager> ObjManager::singleton;

ObjManager::ObjManager()
    :object()
{
    //�����Ȃ�
}

ObjManager::~ObjManager()
{
    //�����Ȃ�
}

void ObjManager::InitObjManager()
{
    //���g�̒��g���󂾂�����C���X�^���X����
    if (!singleton)
    {
        singleton.reset(new ObjManager);
    }
}

void ObjManager::AddObj(ObjBase* newObj)
{
    std::string tag = newObj->GetTag();

    singleton->object[tag].emplace_back(newObj);
}

void ObjManager::UpdateObj(const float deltaTime)
{
    //�S�^�O���X�V�������܂Ƃ߂čs��
    for (auto& tag : objTagAll)
    {
        for (int i = 0; i < singleton->object[tag].size(); i++)
        {
            singleton->object[tag][i]->Update(deltaTime);
        }
    }
    OnDeadObj();
}

void ObjManager::DrawObj()
{
    //�S�^�O���`�揈�����܂Ƃ߂čs��
    for (auto& tag : objTagAll)
    {
        for (int i = 0; i < singleton->object[tag].size(); i++)
        {
            //�I�u�W�F�N�g���������Ă�����`�悳����
            if (singleton->object[tag][i]->IsVisible())
            {
                singleton->object[tag][i]->Draw();
            }
        }
    }
}

void ObjManager::OnDeadObj()
{
    //�S�^�O�����S�I�u�W�F�N�g��T���č폜
    for (auto& tag : objTagAll)
    {
        for (auto& dead: singleton->object[tag])
        {
            //����ł�����I�u�W�F�N�g�폜
            if (!dead->IsAlive())
            {
                DeleteObj(dead);
            }
        }
    }
}

void ObjManager::DeleteObj(std::shared_ptr<ObjBase> unnecObj)
{
    //�폜�I�u�W�F�N�g�̃^�O�擾
    std::string tag = unnecObj->GetTag();

    //�I�u�W�F�N�g������
    auto endObj= singleton->object[tag].end();
    auto findObj = std::find(singleton->object[tag].begin(), endObj, unnecObj);

    //���������疖���Ɉړ������č폜
    if (findObj != endObj)
    {
        std::swap(findObj, endObj);
        singleton->object[tag].pop_back();
    }
}

void ObjManager::DeleteAllObj()
{
    //�󂶂�Ȃ�������I�u�W�F�N�g�폜
    for (auto& tag : objTagAll)
    {
        if (!singleton->object[tag].empty())
        {
            singleton->object[tag].clear();
        }
    }
}