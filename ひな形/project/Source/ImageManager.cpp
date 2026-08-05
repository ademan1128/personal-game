#include "ImageManager.h"
#include "DxLib.h"

int ImageManager::strikeImage = -1;
int ImageManager::defendImage = -1;
int ImageManager::haikeiImage = -1;
int ImageManager::enemy_1image = -1;

void ImageManager::Load()
{
    //strikeImage = LoadGraph("../../project/image/strike.png");
    defendImage = LoadGraph("image/defense.png");
    strikeImage = LoadGraph("image/strike.png");
	haikeiImage = LoadGraph("image/haikei0.png");

    enemy_1image = LoadGraph("image/enemy_1.png");
    
}
