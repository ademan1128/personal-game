#pragma once

#include "Card.h"

class Strike : public Card
{
public:
    Strike();

    void Use(Player& player, Enemy& enemy) override;
};