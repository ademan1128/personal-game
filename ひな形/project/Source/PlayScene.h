#pragma once
#include <vector>
#include <cstring>
#include "../Library/SceneBase.h"
#include "Player.h"
#include "Enemy.h"
#include "Card.h"
#include "Battle.h"

/// <summary>
/// ゲームプレイのシーンを制御する
/// </summary>

enum class GameState
{
	PlayerTurn,
	EnemyTurn,
	GameOver
};

enum class PlayerState
{
	Idle,
	Attacking,
	Defending,
};

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
	bool noCost;
	int FontC;
	int FontN;
};


class Input
{
public:
	static char Pushing[256];                   //今のキーを保存
	static char Pushed[256];                    //前のキーを保存

	static void Update()
	{
		memcpy(Pushed, Pushing, 256);           //今のキーを前のキーに
		GetHitKeyStateAll(Pushing);             //ここで今のキーを取得
	}

	static bool Trigger(int key)
	{
		return Pushing[key] && !Pushed[key];    //前のキーが押されていなくて、今のキーが押されているかを判定
	}
};
