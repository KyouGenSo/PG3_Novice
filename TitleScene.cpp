#include "TitleScene.h"
#include <Novice.h>

void TitleScene::Initialize()
{
}

void TitleScene::Update()
{
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE]) {
		sceneNo = STAGE;
	}
}

void TitleScene::Draw()
{
	Novice::ScreenPrintf(100, 100, "TitleScene");
	Novice::ScreenPrintf(100, 120, "Press Space to Start");
}
