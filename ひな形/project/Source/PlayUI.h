#pragma once
#include "DxLib.h"
#include "DamageText.h"

#include <vector>

class PlayUI
{
public:
    void ShowDamage(int damage);

    void Update();
    void Draw();

private:
    std::vector<DamageText*> damageTexts;
};