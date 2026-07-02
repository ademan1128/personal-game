#include "Character.h"

Character::Character(int hp)
    : HP(hp), Block(0)
{
}

void Character::TakeDamage(int damage)
{
    if (Block >= damage)
    {
        Block -= damage;
    }
    else
    {
        HP -= damage - Block;
        Block = 0;
    }
}