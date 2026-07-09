#pragma once

#include "Card.h"

class Defend : public Card
{
public:
    Defend();

    bool Use(Player& player, Enemy& enemy) override;
};