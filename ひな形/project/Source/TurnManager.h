#pragma once
#include "Command.h"

class TurnManager
{
public:
    enum class State
    {
        PlayerTurn,
        EnemyTurnStart,
        EnemyAttack,
        PlayerTurnStart,
		GameOver
    };

    void Update();
    bool IsEnemyAttack() const;
    bool IsPlayerTurn() const;
	void StartEnemyTurn();
    void EndPlayerTurn();
	bool CanEnemyAttack();
	void GameOver();
    TurnManager(Command& command);

private:
	Command& command;
    State state = State::PlayerTurn;
	bool isStarted = false;
    bool enemyAttacked = false;
};
