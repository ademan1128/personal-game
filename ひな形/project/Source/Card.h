#pragma once

#include <string>

using namespace std;

class Player;
class Enemy;

class Card
{
public:
    int cost;
    string name;
    int imageHandle;

    Card(string n, int c,int image);

    virtual ~Card() = default;

    virtual void Use(Player& player, Enemy& enemy) = 0;
};