#include "Enemy.h"
#include "Player.h"

Enemy::Enemy()
    : Character(50)
{
}

void Enemy::Attack(Player& player)
{
    int damage = 10;
    player.TakeDamage(damage);
}