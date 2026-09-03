#include "Enemy.h"
#include "Player.h"
#include <cstdlib>

int GetRandomValue()
{
    int values[] = { 5, 10, 15, 20, 30 };
    return values[rand() % 5];
}

Enemy::Enemy()
    : Character(50)
{

}

void Enemy::Attack(Player& player)
{
    damage = GetRandomValue();

    player.TakeDamage(damage);
}