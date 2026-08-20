#include "DamageText.h"


DamageText::DamageText(int damage, int x, int y , float scale)
{
    this->damage = damage;
    this->x = x;
    this->y = y;
    this->scale = scale;

    int fontSize = static_cast<int>(64 * scale);
    DamagefontHandle = CreateFontToHandle( nullptr, fontSize,-1,DX_FONTTYPE_NORMAL );
}

DamageText::~DamageText()
{
    DeleteFontToHandle(DamagefontHandle);
}

void DamageText::Update()
{
    y -= speed;
    lifeTime--;
}

void DamageText::Draw()
{
    int fontSize = (int)(64 * scale);

    int fontHandle = CreateFontToHandle(nullptr,fontSize,-1, DX_FONTTYPE_NORMAL);

    DrawFormatStringToHandle((int)x,(int)y,GetColor(255, 255, 255), fontHandle,"%d",damage);

    DeleteFontToHandle(fontHandle);
}

bool DamageText::IsDead() const
{
    return lifeTime <= 0;
}