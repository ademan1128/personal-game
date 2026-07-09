#include "PlayScene.h"
#include "ImageManager.h"


//static変数の定義と初期化
char Input::Pushing[256] = {};  
char Input::Pushed[256] = {};



PlayScene::PlayScene()
{
	ImageManager::Load();

	deck = CardShuffle();

	player.Enargy = 3;
	player.Block = 0;

	DrawCardWithShuffle(deck, discardPile, hand, 5);

	playerTurn = true;
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	Input::Update();

	if (Input::Trigger(KEY_INPUT_0))
	{
		playerTurn = false;
	}


	if (Input::Trigger(KEY_INPUT_1))
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
				DrawFormatString(0, 80, GetColor(255, 255, 255), "コストが足りません");
			}
		}
	}

	// 2キー
	if (Input::Trigger(KEY_INPUT_2))
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
				DrawFormatString(0, 80, GetColor(255, 255, 255), "コストが足りません");
			}
		}
	}

	// 3キー
	if (Input::Trigger(KEY_INPUT_3))
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
				DrawFormatString(0, 80, GetColor(255, 255, 255), "コストが足りません");
			}
		}
	}

	if (Input::Trigger(KEY_INPUT_4))
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
				DrawFormatString(0, 80, GetColor(255, 255, 255), "コストが足りません");
			}
		}
	}

	if (Input::Trigger(KEY_INPUT_5))
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
				DrawFormatString(0, 80, GetColor(255, 255, 255), "コストが足りません");
			}
		}
	}

	if (!playerTurn)
	{

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
	DrawExtendGraph(0, 0,1920,1080,ImageManager::haikeiImage, TRUE);

	DrawFormatString(
		0, 30,
		GetColor(255, 255, 255),
		"Player HP : %d",
		player.HP);
	DrawFormatString(
		100, 60,
		GetColor(255, 255, 255),
		"Enemy HP : %d",
		enemy.HP);
	for (int i = 0; i < hand.size(); i++)
	{
		int x = 100 + i * 120; 
		int y = 500;

		DrawExtendGraph(
			x, y,          // 左上
			x + 100,       // 右
			y + 150,       // 下
			hand[i]->imageHandle,
			TRUE);
	}
	if (!hand.empty())
	{
		DrawFormatString(0, 100, GetColor(255, 255, 255),
			"HandImage=%d", hand[0]->imageHandle);
	}
}

