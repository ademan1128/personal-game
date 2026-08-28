#include "Battle.h"
#include "Strike.h"
#include "Defend.h"
#include <algorithm>
#include <random>

using namespace std;

vector<Card*> CardShuffle()
{
    vector<Card*> deck;

    // Strike5–‡
    for (int i = 0; i < 5; i++)
    {
        deck.push_back(new Strike());
    }

    // Defend5–‡
    for (int i = 0; i < 5; i++)
    {
        deck.push_back(new Defend());
    }

    random_device rnd;
    mt19937 mt(rnd());

    shuffle(deck.begin(), deck.end(), mt);

    return deck;
}

void DrawCardWithShuffle(vector<Card*>& deck, vector<Card*>& discardPile, vector<Card*>& hand, int drawCount)
{
    for (int i = 0; i < drawCount; i++)
    {
        if (deck.empty())
        {
            if (discardPile.empty())
            {
                break;
            }

            deck = discardPile;
            discardPile.clear();

            random_device rnd;
            mt19937 mt(rnd());

            shuffle(deck.begin(), deck.end(), mt);
        }

        hand.push_back(deck.back());
        deck.pop_back();
    }
}