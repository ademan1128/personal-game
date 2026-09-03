#include "ImageManager.h"
#include "DxLib.h"

int ImageManager::strikeImage = -1;
int ImageManager::defendImage = -1;
int ImageManager::haikeiImage = -1;
int ImageManager::characterimage = -1;
int ImageManager::enemyimage = -1;
int ImageManager::titleImage = -1;
void ImageManager::Load()
{
    //strikeImage = LoadGraph("../../project/image/strike.png");
    defendImage = LoadGraph("image/block.png");
    strikeImage = LoadGraph("image/attak.png");
	haikeiImage = LoadGraph("image/haikei0.png");

    characterimage = LoadGraph("image/character.png");
    enemyimage = LoadGraph("image/enemy_1.png");

}
