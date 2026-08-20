#pragma once
#include <string>
#include <queue>
#include <vector>
#include "DxLib.h"

class Command
{
public:
    Command();
	~Command();
    void Attack(const std::string& Message);
    void Cost(const std::string& Message);
    bool IsPlaying() const;
    void Update();
    void Draw();
private:
    std::queue<std::string> Messages;
    std::string currentMessage;

    int timer = 0;
    int displayTime = 30;

    int fontHandle;
};