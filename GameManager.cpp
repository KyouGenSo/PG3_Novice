#include "GameManager.h"
#include <Novice.h>

GameManager::GameManager()
{
	scenes_[0] = std::make_unique<TitleScene>();
	scenes_[1] = std::make_unique<StageScene>();
	scenes_[2] = std::make_unique<ClearScene>();

	currentSceneNo_ = TITLE;
}

GameManager::~GameManager()
{
}

int GameManager::Run()
{

	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame();


		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = scenes_[currentSceneNo_]->GetSceneNo();

		if (prevSceneNo_ != currentSceneNo_) {
			scenes_[currentSceneNo_]->Initialize();
		}

		scenes_[currentSceneNo_]->Update();

		scenes_[currentSceneNo_]->Draw();


		Novice::EndFrame();

		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	return 0;
}
