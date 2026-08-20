#include "command.h"
#include "DxLib.h"
Command::Command()
{
	fontHandle = CreateFontToHandle("ƒƒCƒŠƒI", 48, 2, DX_FONTTYPE_NORMAL);
}

Command::~Command()
{
	DeleteFontToHandle(fontHandle);
}

void Command::Attack(const std::string& Message)
{
	Messages.push(Message);
}

void Command::Cost(const std::string& Message)
{
	Messages.push(Message);
}

void Command::Update()
{
	if (currentMessage.empty() && !Messages.empty())
	{
		currentMessage = Messages.front();
		Messages.pop();
		timer = displayTime;
	}
	else if (!currentMessage.empty())
	{
		timer--;
		if (timer <= 0)
		{
			currentMessage.clear();
		}
	}
}
bool Command::IsPlaying() const
{
	return !currentMessage.empty() || !Messages.empty();
}
void Command::Draw()
{
	if (!currentMessage.empty())
	{
		DrawStringToHandle(850, 540, currentMessage.c_str(), GetColor(255, 255, 255), fontHandle);
	}
}