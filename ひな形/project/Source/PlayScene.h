#pragma once
#include <vector>
#include <cstring>
#include "../Library/SceneBase.h"
#include "Player.h"
#include "Enemy.h"
#include "Card.h"
#include "Battle.h"
#include "PlayUI.h"
#include "Command.h"
#include "TurnManager.h"
/// <summary>
/// ゲームプレイのシーンを制御する
/// </summary>

enum class GameState
{
	PlayerTurn,
	EnemyTurn,
	GameOver
};

enum class PlayerMoveState
{
	Idle,
	AttackMove,
	ReturnMove
};

class PlayScene : public SceneBase
{
public:
	PlayUI playUI;
	Command command;
	Player player;
	Enemy enemy;
	TurnManager turnManager;

	std::vector<Card*> deck;
	std::vector<Card*> hand;
	std::vector<Card*> discardPile;

	bool playerTurn = true;
	PlayScene();
	~PlayScene();
	void Update() override;
	void Draw() override;
	int FontC;
	int FontN;

	PlayerMoveState playerMoveState = PlayerMoveState::Idle;


	float PlayerX = 480;
	float PlayerY = 540;

	const int playerStartX = 480;
	const int playerAttackX = 700;

	float playerSpeed = 0.0f;
	float acceleration = 1.0f;

	bool isAttacking = false;

	void DrawPlayer();
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
