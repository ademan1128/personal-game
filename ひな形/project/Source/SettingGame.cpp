#include <iostream>
#include <algorithm>

#include <vector>
#include <random>

using namespace std;

class Character;//Characterクラスの前方宣言
class Enemy;//Enemyクラスの前方宣言	
class Player;//Playerクラスの前方宣言

class Character {
public:
	int HP;
	int Block;
	Character(int HP) : HP(HP), Block(0) {}//ここでHPを初期化し、Blockは0で初期化

	void TakeDamage(int damage) {
		if (Block >= damage) {
			Block -= damage;
		}
		else {
			int realDamage = damage - Block;
			Block = 0;
			HP -= realDamage;
		}
	}
};//すべてのキャラの基底クラス

class Player : public Character {//Playerクラスは子、Characterクラスは親
public:
	int Enargy;
	Player() : Character(80), Enargy(3) {}//PlayerのコンストラクタでHPを80、エナジーを3に初期

	void Attack(class Enemy& enemy);
};

class Enemy : public Character {
public:
	Enemy() : Character(50) {}//EnemyのコンストラクタでHPを50に初期

	void Attack(class Player& player);
};

void Player::Attack(Enemy& enemy) {//Playerクラスの攻撃関数
	int damage = 10;
	enemy.TakeDamage(damage);//EnemyのTakeDamage関数を呼び出してダメージを与える
}

void Enemy::Attack(Player& player) {//Enemyの攻撃関数
	int damage = 10;
	player.TakeDamage(damage);//PlayerのTakeDamage関数を呼び出してダメージを与える
}

class Card {//カードの基底クラス
public:
	int cost;
	string name;

	Card(string n, int c)
		: name(n), cost(c) {//ここで他のクラスからのデータを受け取み、詰め込む
	}
	virtual void Use(Player& player, Enemy& enemy) = 0;//Use関数を他のクラスで必ず作るようにする
	//Use関数の中で動きをつけるようにする
};

class strike : public Card {
public:
	strike() : Card("Strike", 1) {}//strikeクラスのコンストラクタでカード名を"Strike"、コストを1に決定
	void Use(Player& player, Enemy& enemy) override
	{   //strikeクラスのUse関数
		if (player.Enargy < cost) 
		{
			cout << "エナジーが足りません\n";
			return;
		}
		player.Enargy -= cost;//プレイヤーのエナジーからコストを引く
		int damage = 6;
		enemy.TakeDamage(damage);//EnemyのTakeDamage関数を呼び出してダメージを与える
	}
};

class defend : public Card {
public:
	defend() : Card("Defend", 1) {}//defendクラスのコンストラクタでカード名を"Defend"、コストを1に決定
	void Use(Player& player, Enemy& enemy) override
	{   //defendクラスのUse関数
		if (player.Enargy < cost) 
		{
			cout << "エナジーが足りません\n";
			return;
		}
		player.Enargy -= cost;//プレイヤーのエナジーからコストを引く
		player.Block += 5;//プレイヤーのBlockに5加算
	}
};

vector<Card*> CardShuffle() 
{
	vector<Card*> deck;//山札のプールを作成している
	//デッキに追加
	for (int i = 0; i < 5; i++)
	{
		deck.push_back(new strike());//strikeをdackの後ろに追加
	}

	for (int i = 0; i < 5; i++)
	{
		deck.push_back(new defend());//defendをdackの後ろに追加
	}

	random_device rnd;//ランダムに数値を生成するためのオブジェクト
	mt19937 mt(rnd());

	shuffle(deck.begin(), deck.end(), mt);//deckのカードをランダムにシャッフルする。shuffle(開始位置, 終了位置, 乱数生成器)

	return deck;

}


void DrawCardWithShuffle(vector<Card*>& deck, vector<Card*>& discardPile, vector<Card*>& hand, int drawCount) 
{
	for (int i = 0; i < drawCount; i++) 
	{
		if (deck.empty()) //デッキが空の場合
		{
			if (discardPile.empty()) //捨て札も空の場合はドローできないのでループを抜ける
			{
				break;
			}
			deck = discardPile;//捨て札をデッキに移す
			discardPile.clear();//捨て札を空にする
			random_device rnd;
			mt19937 mt(rnd());
			shuffle(deck.begin(), deck.end(), mt);//デッキをシャッフルする
			cout << "デッキがシャッフルされました\n";
		}
		hand.push_back(deck.back());
		deck.pop_back();
	}
}
void BattleLoop()
{

	Player player;
	Enemy enemy;
	bool playerTurn = true;
	vector<Card*> deck = CardShuffle();
	vector<Card*> hand;
	vector<Card*> discardPile;

	while (player.HP > 0 && enemy.HP > 0) 
	{
		int choice;
		player.Enargy = 3;
		player.Block = 0;

		DrawCardWithShuffle(deck, discardPile, hand, 5);

		while (playerTurn == true)
		{

			for (int i = 0; i < hand.size(); i++)
			{
				cout << i + 1 << " : " << hand[i]->name << " Cost:" << hand[i]->cost << endl;//手札表示
			}

			cout << "0 : ターン終了" << endl;

			cin >> choice;

			if (choice == 0)
			{
				playerTurn = false;
				break;
			}

			if (choice >= 1 && choice <= hand.size())
			{
				int index = choice - 1;

				if (player.Enargy >= hand[index]->cost)//持っているエナジーがカードのコスト以上であればを判定する
				{
					hand[index]->Use(player, enemy);//handのindex番目のカードのUse関数を呼び出す

					discardPile.push_back(hand[index]);//使用したカードを捨て札に移す
					hand.erase(hand.begin() + index);//使用したカードを手札から削除する
					if (enemy.HP <= 0)
					{
						cout << "You Win!\n";
						return;
					}
				}
				else
				{
					cout << "エナジーが足りません\n";
				}
			}
		}
		if (enemy.HP <= 0) {
			cout << "You Win!\n";
			break;
		}


		for (Card* card : hand) {
			discardPile.push_back(card);
		}
		hand.clear(); // 手札を空にする

		if (enemy.HP > 0)
		{
			enemy.Attack(player);
			playerTurn = true;
		}

		cout << "Player HP: " << player.HP << " Enemy HP: " << enemy.HP << "\n";

		if (player.HP <= 0)
		{
			cout << "Game Over\n";
			break;
		}
	}
}

int main() {
	BattleLoop();
}