#include "Player.h"
#include "Enemy.h"

Player::Player()
    : Character(80), Enargy(3)
{
}

void Player::Attack(Enemy& enemy)
{
    int damage = 10;
    enemy.TakeDamage(damage);
}