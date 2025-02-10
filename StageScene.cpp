#include "StageScene.h"
#include <Novice.h>

void StageScene::Initialize()
{
	enemyHP = 100;

	enemyPos.x = 640;
	enemyPos.y = 360;
	enemySize.x = 20;
	enemySize.y = 20;
	enemyHpPos.x = enemyPos.x;
	enemyHpPos.y = enemyPos.y - 10;

	playerPos.x = 500;
	playerPos.y = 300;
	bulletPos = playerPos;
	bulletSize.x = 5;
	bulletSize.y = 5;
	isShot = false;
}

void StageScene::Update()
{

	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

	PlayerMove();
	PlayerAttack();


	if (enemyHP <= 0)
	{
		sceneNo = CLEAR;
	}
}

void StageScene::Draw()
{
	Novice::DrawBox(int(enemyHpPos.x - 43.f), int(enemyHpPos.y), int(enemyHP), 5, 0.0f, RED, kFillModeSolid);

	Novice::DrawBox(int(enemyPos.x), int(enemyPos.y), int(enemySize.x), int(enemySize.y), 0.0f, GREEN, kFillModeSolid);

	Novice::DrawBox(int(playerPos.x), int(playerPos.y), 20, 20, 0.0f, BLUE, kFillModeSolid);

	if (isShot)
	{
		Novice::DrawBox(int(bulletPos.x), int(bulletPos.y), int(bulletSize.x), int(bulletSize.y), 0.0f, WHITE, kFillModeSolid);
	}

	Novice::ScreenPrintf(100, 100, "StageScene");
	Novice::ScreenPrintf(100, 120, "Press Space to Attack");
}

void StageScene::PlayerMove()
{
	if (keys[DIK_W] != 0)
	{
		playerPos.y -= 1;
	}

	if (keys[DIK_S] != 0)
	{
		playerPos.y += 1;
	}

	if (keys[DIK_A] != 0)
	{
		playerPos.x -= 1;
	}

	if (keys[DIK_D] != 0)
	{
		playerPos.x += 1;
	}

	if (playerPos.x < 0)
	{
		playerPos.x = 0;
	}

	if (playerPos.x > 1280)
	{
		playerPos.x = 1280;
	}

	if (playerPos.y < 0)
	{
		playerPos.y = 0;
	}

	if (playerPos.y > 720)
	{
		playerPos.y = 720;
	}
}

void StageScene::PlayerAttack()
{
	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] && !isShot)
	{
		bulletPos = playerPos;
		isShot = true;
	}

	if (isShot)
	{
		bulletPos.y -= 10;

		if (bulletPos.y < 0)
		{
			isShot = false;
		}

		if (bulletPos.x > enemyPos.x - 10 && bulletPos.x < enemyPos.x + 10 && bulletPos.y > enemyPos.y - 10 && bulletPos.y < enemyPos.y + 10)
		{
			enemyHP -= 20;
			isShot = false;
		}
	}
}
