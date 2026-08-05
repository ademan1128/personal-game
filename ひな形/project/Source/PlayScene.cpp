#include "PlayScene.h"
#include "ImageManager.h"
#include "Trigger.h"

//static変数の定義と初期化
char Input::Pushing[256] = {};
char Input::Pushed[256] = {};

void DrawPlayer();
void DrawMovePlayer();

PlayScene::PlayScene()
{
	ImageManager::Load();

	deck = CardShuffle();

	player.Enargy = 3;
	player.Block = 0;

	DrawCardWithShuffle(deck, discardPile, hand, 5);

	playerTurn = true;
	
	noCost = false;

	FontC = CreateFontToHandle(NULL, 48, 2, DX_FONTTYPE_NORMAL);
	FontN = CreateFontToHandle("メイリオ", 48, 2, DX_FONTTYPE_NORMAL);
}

PlayScene::~PlayScene()
{
	DeleteFontToHandle(FontN);
}

void PlayScene::Update()
{


	Input::Update();

	if (player.Enargy <= 0) {
		noCost = true;
	}

	if (KeyTrigger::CheckTrigger(KEY_INPUT_0))
	{
		playerTurn = false;
	}


	if (KeyTrigger::CheckTrigger(KEY_INPUT_1))
	{
		if (hand.size() > 0)
		{
			if (hand[0]->Use(player, enemy))
			{
				discardPile.push_back(hand[0]);
				hand.erase(hand.begin() + 0);
			}
			else
			{
				noCost = true;
			}
		}
	}

	// 2キー
	if (KeyTrigger::CheckTrigger(KEY_INPUT_2))
	{
		if (hand.size() > 1)
		{
			if (hand[1]->Use(player, enemy))
			{
				discardPile.push_back(hand[1]);
				hand.erase(hand.begin() + 1);
			}
			else
			{
				noCost = true;
			}
		}
	}

	// 3キー
	if (KeyTrigger::CheckTrigger(KEY_INPUT_3))
	{
		if (hand.size() > 2)
		{
			if (hand[2]->Use(player, enemy))
			{
				discardPile.push_back(hand[2]);
				hand.erase(hand.begin() + 2);
			}
			else
			{
				noCost = true;
			}
		}
	}

	// 4キー
	if (KeyTrigger::CheckTrigger(KEY_INPUT_4))
	{
		if (hand.size() > 3)
		{
			if (hand[3]->Use(player, enemy))
			{
				discardPile.push_back(hand[3]);
				hand.erase(hand.begin() + 3);
			}
			else
			{
				noCost = true;
			}
		}
	}


	//5キー
	if (KeyTrigger::CheckTrigger(KEY_INPUT_5))
	{
		if (hand.size() > 4)
		{
			if (hand[4]->Use(player, enemy))
			{
				discardPile.push_back(hand[4]);
				hand.erase(hand.begin() + 4);
			}
			else
			{
				noCost = true;
			}
		}
	}

	if (!playerTurn)
	{
		noCost = false;
		enemy.Attack(player);


		for (Card* card : hand)
		{
			discardPile.push_back(card);
		}
		hand.clear();


		player.Enargy = 3;
		player.Block = 0;

		DrawCardWithShuffle(deck, discardPile, hand, 5);

		playerTurn = true;

	}

}

void PlayScene::Draw()
{
	Player* p = FindGameObject<Player>();
	DrawExtendGraph(0, 0, 1920, 708, ImageManager::haikeiImage, TRUE);

	//DrawExtendGraph(0, 0, 64, 64, , TRUE);

	DrawPlayer();

	DrawExtendFormatStringToHandle(50, 740, 2, 2, GetColor(255, 255, 255), GetDefaultFontHandle(), "cost:%d", player.Enargy);


	DrawFormatString(0, 30,GetColor(255, 255, 255),"Player HP : %d",player.HP);
	DrawFormatString(100, 60,GetColor(255, 255, 255),"Enemy HP : %d",enemy.HP);
	for (int i = 0; i < hand.size(); i++)
	{
		int x = 216 + i * 300;
		int y = 700;

		DrawExtendGraph(x, y,x + 200,y + 300,hand[i]->imageHandle,TRUE);
	}

	if (noCost)
	{
		DrawStringToHandle(750, 540, "コストが足りません", GetColor(255, 255, 255), FontN);
	}

}

void DrawPlayer()
{
	DrawRectGraph(480, 540, 64, 64,64,64, ImageManager::enemy_1image,TRUE);

};

void DrawMovePlayer() 
{

}