#pragma once

#include <vector>
#include "Card.h"

using namespace std;

vector<Card*> CardShuffle();

void DrawCardWithShuffle(
    vector<Card*>& deck,
    vector<Card*>& discardPile,
    vector<Card*>& hand,
    int drawCount
);