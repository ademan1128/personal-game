#include "Defend.h"
#include "Player.h"
#include "ImageManager.h"
Defend::Defend()
    : Card("Defend", 1, ImageManager:: defendImage)
{
}

bool Defend::Use(Player& player, Enemy&)
{
    if (player.Enargy < cost)
    {
        return false;
    }

    player.Enargy -= cost;
    player.Block += 5;
	return true;
}