#pragma once

class Character
{
public:
    int HP;
    int Block;

    Character(int hp);

    void TakeDamage(int damage);
};