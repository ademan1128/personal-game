#include "Strike.h"
#include "Player.h"
#include "Enemy.h"
#include "ImageManager.h"

Strike::Strike()
    : Card("Strike", 1, ImageManager::strikeImage)
{
}

bool Strike::Use(Player& player, Enemy& enemy)
{
    if (player.Enargy < cost)
    {
        return false;
    }

    player.Enargy -= cost;

    int damage = 10;
    enemy.TakeDamage(damage);
	return true;
}