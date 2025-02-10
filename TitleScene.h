#pragma once
#include "IScene.h"

class TitleScene : public IScene {
public:
	void Initialize() override;
	void Update() override;
	void Draw() override;

	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
};