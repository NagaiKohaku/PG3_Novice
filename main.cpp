#include <Novice.h>
#include "GameManeger.h"

const char kWindowTitle[] = "LE2C_18_ナガイ_コハク_PG3_04_01_ステートパターンとシーン遷移";

// Windowsアプリでのmain関数
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	//GameManegerクラスのインスタンスを作成する
	GameManeger* gameManeger = new GameManeger();

	//GameManegerクラスからメンバ関数Runを呼び出す
	gameManeger->Run();

	// ライブラリの終了
	Novice::Finalize();

	//GameManegerを解放
	delete gameManeger;

	return 0;
}
