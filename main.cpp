#include <Novice.h>
#include "GameManager.h"

const char kWindowTitle[] = "LE2B_10_キョウ_ゲンソ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);


	// ゲームマネージャーのインスタンスを生成
	GameManager gameManager;

	// ゲームのメインループ
	gameManager.Run();

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
