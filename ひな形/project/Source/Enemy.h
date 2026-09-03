#pragma once
#include "Character.h"

class Player; // ‘O•ûéŒ¾

class Enemy : public Character
{
public:
    Enemy();

    void Attack(Player& player);
    int damage = 0;
};