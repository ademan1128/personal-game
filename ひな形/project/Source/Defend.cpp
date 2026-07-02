#include "Defend.h"
#include "Player.h"
#include "ImageManager.h"
Defend::Defend()
    : Card("Defend", 1, ImageManager:: defendImage)
{
}

void Defend::Use(Player& player, Enemy&)
{
    if (player.Enargy < cost)
    {
        return;
    }

    player.Enargy -= cost;
    player.Block += 5;
}