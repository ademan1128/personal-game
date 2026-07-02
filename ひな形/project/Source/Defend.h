#pragma once

#include "Card.h"

class Defend : public Card
{
public:
    Defend();

    void Use(Player& player, Enemy& enemy) override;
};