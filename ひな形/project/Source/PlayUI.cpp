#include "PlayUI.h"


void PlayUI::ShowDamage(int damage)
{
    //ここでテキスト調整
    DamageText* text = new DamageText(damage,700,500, 1.0f);

    damageTexts.push_back(text);
}

void PlayUI::Update()
{
    for (DamageText* text : damageTexts)
    {
        text->Update();
    }

    for (auto it = damageTexts.begin(); it != damageTexts.end();)
    {
        if ((*it)->IsDead())
        {
            delete* it;
            it = damageTexts.erase(it);
        }
        else
        {
            ++it;
        }
    }
}
void PlayUI::Draw()
{
    for (DamageText* text : damageTexts)
    {
        text->Draw();
    }
}