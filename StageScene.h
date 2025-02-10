#pragma once
#include "IScene.h"
#include "Vector2.h"

class StageScene : public IScene {
public:
	void Initialize() override;
	void Update() override;
	void Draw() override;

	void PlayerMove();
	void PlayerAttack();

	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

public:

	Vector2 playerPos;
	Vector2 enemyPos;
	Vector2 enemySize;
	Vector2 enemyHpPos;
	Vector2 bulletPos;
	Vector2 bulletSize;
	int enemyHP;
	bool isShot;

};