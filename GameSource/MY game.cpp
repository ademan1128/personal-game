#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <random>

using namespace std;

class Character;//Characterクラスの前方宣言
class Enemy;//Enemyクラスの前方宣言	
class Player;//Playerクラスの前方宣言
int SetMouseDispFlag(false);
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
	void Use(Player& player, Enemy& enemy) override {//strikeクラスのUse関数
		if (player.Enargy < cost) {
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
	void Use(Player& player, Enemy& enemy) override {//defendクラスのUse関数
		if (player.Enargy < cost) {
			cout << "エナジーが足りません\n";
			return;
		}
		player.Enargy -= cost;//プレイヤーのエナジーからコストを引く
		player.Block += 5;//プレイヤーのBlockに5加算
	}
};

vector<Card*> CardShuffle() {
	vector<Card*> deck;
	vector<Card*> hand;
	//デッキに追加
	for (int i = 0; i < 5; i++)
	{
		deck.push_back(new strike());
	}

	for (int i = 0; i < 5; i++)
	{
		deck.push_back(new defend());
	}

	random_device rnd;//ランダムに数値を生成するためのオブジェクト
	mt19937 mt(rnd());

	shuffle(deck.begin(), deck.end(), mt);//deckのカードをランダムにシャッフルする。shuffle(開始位置, 終了位置, 乱数生成器)

	return deck;

}

void BattleLoop()
{

	Player player;
	Enemy enemy;
	bool playerTurn = true;
	vector<Card*> deck = CardShuffle();
	vector<Card*> hand;

	while (player.HP > 0 && enemy.HP > 0) {	int choice;
	player.Enargy = 3;
	player.Block = 0;
	for (int i = 0; i < 5; i++)
	{
		hand.push_back(deck.back());
		deck.pop_back();
	}

	while (playerTurn == true)
	{

		if (enemy.HP <= 0) {
			cout << "You Win!\n";
			break;
		}
		choice = 0;
		::cout << "1:攻撃 2:防御 3:ターン終了\n";
		::cin >> choice;
		for (int i = 0; i < hand.size(); i++)
		{
			cout << i + 1
				<< ": "
				<< hand[i]->name
				<< endl;
		}
		if (choice == 1) {
			if (player.Enargy <= 0) {
				::cout << "エナジーが足りません\n";
				continue;
			}
			player.Attack(enemy);
			player.Enargy -= 1;
			cout << "Player HP: " << player.HP << " Enemy HP: " << enemy.HP << "\n";
			if (enemy.HP <= 0) {
				cout << "You Win!\n";
				break;
			}
		}
		else if (choice == 2) {
			if (player.Enargy <= 0) {
				cout << "エナジーが足りません\n";
				continue;
			}
			player.Block += 5;
			player.Enargy -= 1;
		}
		else if (choice == 3) {
			cout << "ターン終了\n";
			playerTurn = false;
		}
	}
	if(enemy.HP > 0) 
	{
		enemy.Attack(player);
		playerTurn = true;
	}

		cout << "Player HP: " << player.HP << " Enemy HP: " << enemy.HP << "\n";
		if (player.HP <= 0) {
			cout << "Game Over\n";
			break;
		}
	}
}

int main() {
	BattleLoop();
}