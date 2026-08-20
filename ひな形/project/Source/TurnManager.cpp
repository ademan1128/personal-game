#include "TurnManager.h"

TurnManager::TurnManager(Command& command)
    : command(command)
{
    state = State::PlayerTurn;
    isStarted = false;
    enemyAttacked = false;
}

void TurnManager::Update()
{
    {
        switch (state)
        {
        case State::PlayerTurn:
            break;

        case State::EnemyTurnStart:
            if (!isStarted)
            {
                command.Attack("Enemyのターン！");
                isStarted = true;
            }
            if (isStarted && !command.IsPlaying())
            {
                state = State::EnemyAttack;
                isStarted = false;
            }

            break;

        case State::EnemyAttack:

            if (!isStarted)
            {
                command.Attack("Enemyの攻撃！");
                isStarted = true;
            }

            if (isStarted && !command.IsPlaying())
            {
                state = State::PlayerTurnStart;
                isStarted = false;
            }

            break;

        case State::PlayerTurnStart:

            if (!isStarted)
            {
                command.Attack("Playerのターン！");
                isStarted = true;
            }

            if (isStarted && !command.IsPlaying())
            {
                state = State::PlayerTurn;
                isStarted = false;
            }

            break;
        }
    }

}


bool TurnManager::CanEnemyAttack()
{
    if (state == State::EnemyAttack && !enemyAttacked)
    {
        enemyAttacked = true;
        return true;
    }

    return false;
}

void TurnManager::StartEnemyTurn()
{
    state = State::EnemyTurnStart;
    isStarted = false;
    enemyAttacked = false;
}

void TurnManager::EndPlayerTurn()
{
    if (state == State::PlayerTurn)
    {
        StartEnemyTurn();
    }
}

bool TurnManager::IsPlayerTurn() const
{
	return state == State::PlayerTurn;
}

bool TurnManager::IsEnemyAttack() const
{
    return state == State::EnemyAttack;
}

void TurnManager::GameOver()
{
    command.Attack("GameOver");
    state = State::GameOver;
}