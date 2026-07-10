#pragma once
#include "Character.h"

class Enemy;

class Player : public Character
{
public:
    int Enargy;

    Player();

    void Attack(Enemy& enemy);/*
    auto GetEnargy() const{ return Enargy; }*/
};
