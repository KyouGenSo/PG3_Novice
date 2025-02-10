#pragma once

#include <memory>
#include "IScene.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ClearScene.h"

class GameManager {
private:


	std::unique_ptr<IScene> scenes_[3];

	int currentSceneNo_;
	int prevSceneNo_;


public:
	GameManager();
	~GameManager();

	int Run();

	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
};