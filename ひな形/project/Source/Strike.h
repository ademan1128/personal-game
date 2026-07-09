#pragma once

#include "Card.h"

class Strike : public Card
{
public:
    Strike();

    bool Use(Player& player, Enemy& enemy) override;
};