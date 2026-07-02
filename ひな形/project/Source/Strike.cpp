#include "Strike.h"
#include "Player.h"
#include "Enemy.h"
#include "ImageManager.h"

Strike::Strike()
    : Card("Strike", 1, ImageManager::strikeImage)
{
}

void Strike::Use(Player& player, Enemy& enemy)
{
    if (player.Enargy < cost)
    {
        return;
    }

    player.Enargy -= cost;

    int damage = 6;
    enemy.TakeDamage(damage);
}