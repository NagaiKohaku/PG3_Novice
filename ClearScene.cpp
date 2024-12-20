#include "ClearScene.h"

void ClearScene::Initialize() {
}

void ClearScene::Update(char* keys, char* preKeys) {

	//タブキーを押した瞬間
	if (keys[DIK_TAB] && preKeys[DIK_TAB] == false) {
		//シーンをTITLEに切り替える
		sceneNo = Scene::TITLE;
	}
}

void ClearScene::Draw() {
	Novice::ScreenPrintf(0, 0, "Clear Scene");
	Novice::ScreenPrintf(0, 30, "Push Tab");
}
