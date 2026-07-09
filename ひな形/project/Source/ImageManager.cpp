#include "ImageManager.h"
#include "DxLib.h"

int ImageManager::strikeImage = -1;
int ImageManager::defendImage = -1;
int ImageManager::haikeiImage = -1;

void ImageManager::Load()
{
    //strikeImage = LoadGraph("../../project/image/strike.png");
    defendImage = LoadGraph("C:/Users/adema/Desktop/新しいフォルダー (5)/ひな形/project/image/defense.png");
    strikeImage = LoadGraph("C:/Users/adema/Desktop/新しいフォルダー (5)/ひな形/project/image/strike.png");
	haikeiImage = LoadGraph("C:/Users/adema/Desktop/新しいフォルダー (5)/ひな形/project/image/haikei.png");
}
