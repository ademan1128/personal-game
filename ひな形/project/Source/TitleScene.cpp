#include "TitleScene.h"
#include "ImageManager.h"

TitleScene::TitleScene()
{
	titleImage = LoadGraph("image/haikei1.png");
	font = CreateFontToHandle("メイリオ", 60, 2, DX_FONTTYPE_NORMAL);
}

TitleScene::~TitleScene()
{

}

void TitleScene::Update()
{
	if (CheckHitKey(KEY_INPUT_P)) {
		SceneManager::ChangeScene("PLAY");
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		SceneManager::Exit();
	}
}


void TitleScene::Draw()
{
	DrawExtendGraph(0, 0, 1920, 1080, titleImage, TRUE);

	extern const char* Version();

	int width = GetDrawStringWidthToHandle("Push [P]Key To Play",1,font);
	DrawStringToHandle(700, 500, "スライムクエスト", GetColor(255, 255, 255), font);
	DrawStringToHandle(700 ,900,"Push [P]Key To Play",GetColor(255, 255, 255),font);
}
