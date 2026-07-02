#pragma once
#include <vector>
#include "../Library/SceneBase.h"
#include "Player.h"
#include "Enemy.h"
#include "Card.h"
#include "Battle.h"

/// <summary>
/// ゲームプレイのシーンを制御する
/// </summary>
/// 
/// 
class PlayScene : public SceneBase
{
public:
	Player player;
	Enemy enemy;

	std::vector<Card*> deck;
	std::vector<Card*> hand;
	std::vector<Card*> discardPile;

	bool playerTurn = true;

	PlayScene();
	~PlayScene();
	void Update() override;
	void Draw() override;

};
