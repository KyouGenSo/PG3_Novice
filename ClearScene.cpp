#include "ClearScene.h"
#include <Novice.h>

void ClearScene::Initialize()
{
}

void ClearScene::Update()
{
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

	if (preKeys[DIK_RETURN] == 0 && keys[DIK_RETURN]) {
		sceneNo = TITLE;
	}
}

void ClearScene::Draw()
{
	Novice::ScreenPrintf(100, 100, "ClearScene");
	Novice::ScreenPrintf(100, 120, "Press Enter to Title");
}
