#pragma once
#include <DxLib.h>
class DamageText
{
public:
    DamageText(int damage, int x, int y, float scale);
	~DamageText();

    void Update();
    void Draw();

    bool IsDead() const;

private:
    int damage;
    float x;
    float y;
    float scale;

	int DamagefontHandle;

    float speed = 2.0f;
    int lifeTime = 60;
};
