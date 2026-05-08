#include <iostream>
#include <algorithm>

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

class Player : public Character {
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

void Player::Attack(Enemy& enemy) {//Playerの攻撃関数
	int damage = 10;
	enemy.TakeDamage(damage);//EnemyのTakeDamage関数を呼び出してダメージを与える
}

void Enemy::Attack(Player& player) {//Enemyの攻撃関数
	int damage = 10;
	player.TakeDamage(damage);//PlayerのTakeDamage関数を呼び出してダメージを与える
}

void BattleLoop()
{

	Player player;
	Enemy enemy;
	bool playerTurn = true;

	while (player.HP > 0 && enemy.HP > 0) {	int choice;
	player.Enargy = 3;
	player.Block = 0;
	while (playerTurn == true)
	{
		if (enemy.HP <= 0) {
			std::cout << "You Win!\n";
			break;
		}
		choice = 0;
		std::cout << "1:攻撃 2:防御 3:ターン終了\n";
		std::cin >> choice;

		if (choice == 1) {
			if (player.Enargy <= 0) {
				std::cout << "エナジーが足りません\n";
				continue;
			}
			player.Attack(enemy);
			player.Enargy -= 1;
			std::cout << "Player HP: " << player.HP << " Enemy HP: " << enemy.HP << "\n";
			if (enemy.HP <= 0) {
				std::cout << "You Win!\n";
				break;
			}
		}
		else if (choice == 2) {
			if (player.Enargy <= 0) {
				std::cout << "エナジーが足りません\n";
				continue;
			}
			player.Block += 5;
			player.Enargy -= 1;
		}
		else if (choice == 3) {
			std::cout << "ターン終了\n";
			playerTurn = false;
		}
	}
	if(enemy.HP > 0) 
	{
		enemy.Attack(player);
		playerTurn = true;
	}

		std::cout << "Player HP: " << player.HP << " Enemy HP: " << enemy.HP << "\n";
		if (player.HP <= 0) {
			std::cout << "Game Over\n";
			break;
		}
	}
}

int main() {
	BattleLoop();
}