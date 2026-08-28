#include "PlayScene.h"
#include "ImageManager.h"
#include "Trigger.h"
#include "Strike.h"

// static変数の定義と初期化
char Input::Pushing[256] = {};
char Input::Pushed[256] = {};

float inputInterval = 0.5f;   // インターバル
float inputTimer = 0.0f;

PlayScene::PlayScene() : turnManager(command)
{
    ImageManager::Load();

    deck = CardShuffle();

    player.Enargy = 3;
    player.Block = 0;

    DrawCardWithShuffle(deck, discardPile, hand, 5);


    FontC = CreateFontToHandle(NULL, 48, 2, DX_FONTTYPE_NORMAL);
    FontN = CreateFontToHandle("メイリオ", 48, 2, DX_FONTTYPE_NORMAL);
}

PlayScene::~PlayScene()
{
    DeleteFontToHandle(FontN);
}

void PlayScene::Update()
{

    if (isGameOver)
    {
        gameOverTimer += 1.0f / 60.0f;

        if (gameOverTimer >= 2.0f)
        {
            SceneManager::ChangeScene("Title");
        }

        return;
    }
    Input::Update();
    command.Update();
    turnManager.Update();

    // PlayUI更新
    playUI.Update();

    if (turnManager.IsPlayerTurn()) {
        if (playerMoveState == PlayerMoveState::AttackMove)
        {
            PlayerX += playerSpeed;
            playerSpeed += acceleration;

            // 敵に到着
            if (PlayerX >= playerAttackX)
            {
                PlayerX = playerAttackX;

                int damage = 10;
                playUI.ShowDamage(damage);

                playerSpeed = 5.0f;

                playerMoveState = PlayerMoveState::ReturnMove;
            }
        }
        else if (playerMoveState == PlayerMoveState::ReturnMove)
        {
            PlayerX -= playerSpeed;
            playerSpeed += acceleration;

            // 元の位置に到着
            if (PlayerX <= playerStartX)
            {
                PlayerX = playerStartX;
                playerSpeed = 0.0f;
                playerMoveState = PlayerMoveState::Idle;
            }
        }

        if (inputTimer > 0.0f)
        {
            inputTimer -= 1.0f / 60.0f;
        }

        if (inputTimer > 0.0f)
        {
            return;
        }

        if (KeyTrigger::CheckTrigger(KEY_INPUT_0))
        {
            turnManager.EndPlayerTurn();
        }

        //1キー
        if (KeyTrigger::CheckTrigger(KEY_INPUT_1))
        {
            if (hand.size() > 0)
            {
                Card* card = hand[0];

                if (card->Use(player, enemy))
                {
                    // Strikeなら攻撃モーション開始
                    if (dynamic_cast<Strike*>(card) != nullptr)
                    {
                        playerMoveState = PlayerMoveState::AttackMove;
                        command.Attack("Playerの攻撃！");
                        playerSpeed = 2.0f;
                    }

                    discardPile.push_back(card);
                    hand.erase(hand.begin());
                    if (enemy.HP <= 0)
                    {
                        command.Attack("Enemyは倒れた！");
                        command.Attack("GAMECLEAR！");

                        SceneManager::ChangeScene("Title");
                        return;
                    }

                    inputTimer = inputInterval;
                }
                else
                {
                    command.Cost("コストが足りません");;
                }
            }
        }

        // 2キー
        if (KeyTrigger::CheckTrigger(KEY_INPUT_2))
        {
            if (hand.size() > 1)
            {
                Card* card = hand[1];

                if (card->Use(player, enemy))
                {
                    if (dynamic_cast<Strike*>(card) != nullptr)
                    {
                        playerMoveState = PlayerMoveState::AttackMove;
                        command.Attack("Playerの攻撃！");
                        playerSpeed = 2.0f;
                    }

                    discardPile.push_back(card);
                    hand.erase(hand.begin() + 1);
                    if (enemy.HP <= 0)
                    {
                        command.Attack("Enemyは倒れた！");
                        command.Attack("GAMECLEAR！");

                        SceneManager::ChangeScene("Title");
                        return;
                    }
                    inputTimer = inputInterval;
                }
                else
                {
                    command.Cost("コストが足りません");;
                }
            }
        }

        // 3キー
        if (KeyTrigger::CheckTrigger(KEY_INPUT_3))
        {
            if (hand.size() > 2)
            {
                Card* card = hand[2];

                if (card->Use(player, enemy))
                {
                    if (dynamic_cast<Strike*>(card) != nullptr)
                    {
                        playerMoveState = PlayerMoveState::AttackMove;
                        command.Attack("Playerの攻撃！");
                        playerSpeed = 2.0f;
                    }

                    discardPile.push_back(card);
                    hand.erase(hand.begin() + 2);
                    if (enemy.HP <= 0)
                    {
                        command.Attack("Enemyは倒れた！");
                        command.Attack("GAMECLEAR！");

                        SceneManager::ChangeScene("Title");
                        return;
                    }
                    inputTimer = inputInterval;
                }
                else
                {
                    command.Cost("コストが足りません");;
                }
            }
        }

        // 4キー
        if (KeyTrigger::CheckTrigger(KEY_INPUT_4))
        {
            if (hand.size() > 3)
            {
                Card* card = hand[3];

                if (card->Use(player, enemy))
                {
                    if (dynamic_cast<Strike*>(card) != nullptr)
                    {
                        playerMoveState = PlayerMoveState::AttackMove;
                        command.Attack("Playerの攻撃！");
                        playerSpeed = 2.0f;
                    }

                    discardPile.push_back(card);
                    hand.erase(hand.begin() + 3);
                    if (enemy.HP <= 0)
                    {
                        command.Attack("Enemyは倒れた！");
                        command.Attack("GAMECLEAR！");

                        SceneManager::ChangeScene("Title");
                        return;
                    }
                    inputTimer = inputInterval;
                }
                else
                {
                    command.Cost("コストが足りません");;
                }
            }
        }

        // 5キー
        if (KeyTrigger::CheckTrigger(KEY_INPUT_5))
        {
            if (hand.size() > 4)
            {
                Card* card = hand[4];

                if (card->Use(player, enemy))
                {
                    if (dynamic_cast<Strike*>(card) != nullptr)
                    {
                        playerMoveState = PlayerMoveState::AttackMove;
                        command.Attack("Playerの攻撃！");
                        playerSpeed = 2.0f;
                    }

                    discardPile.push_back(card);
                    hand.erase(hand.begin() + 4);
                    if (enemy.HP <= 0)
                    {
                        command.Attack("Enemyは倒れた！");
                        command.Attack("GAMECLEAR！");

                        SceneManager::ChangeScene("Title");
                        return;
                    }
                    inputTimer = inputInterval;
                }
                else
                {
                    command.Cost("コストが足りません");;
                }
            }
        }

    }

    if (turnManager.CanEnemyAttack())
    {

        enemy.Attack(player);
        command.Attack("Playerは10ダメージ受けた！");
        if (player.HP <= 0)
        {
            command.Attack("Playerは倒れた！");
            command.Attack("GAMEOVER！");

            isGameOver = true;
            gameOverTimer = 0.0f;
            return;
        }
        for (Card* card : hand)
        {
            discardPile.push_back(card);
        }

        hand.clear();

        // 次のプレイヤーターンの準備
        player.Enargy = 3;
        player.Block = 0;

        DrawCardWithShuffle(deck, discardPile, hand, 5);
    }
}


void PlayScene::Draw()
{
    DrawExtendGraph(0, 0,1920, 708,ImageManager::haikeiImage,TRUE);

    DrawPlayer();
    playUI.Draw();
	command.Draw();

    DrawExtendFormatStringToHandle(50, 740,2, 2, GetColor(255, 255, 255),GetDefaultFontHandle(), "cost:%d", player.Enargy);

    DrawFormatString(0, 30,GetColor(255, 255, 255), "Player HP : %d", player.HP);

    DrawFormatString(100, 60, GetColor(255, 255, 255),"Enemy HP : %d",enemy.HP);

    for (int i = 0; i < hand.size(); i++)
    {
        int x = 216 + i * 300;
        int y = 750;

        DrawExtendGraph(x, y, x + 200, y + 300, hand[i]->imageHandle,TRUE);
    }

}

void PlayScene::DrawPlayer()
{
    DrawRectGraph( PlayerX, PlayerY,64, 64,64, 64,ImageManager::enemy_1image,TRUE);
}