#include "TitleScene.h"

void TitleScene::Initialize() {
}

void TitleScene::Update(char* keys, char* preKeys) {

	//タブキーを押した瞬間
	if (keys[DIK_TAB] && preKeys[DIK_TAB] == false) {
		//シーンをSTAGEに切り替える
		sceneNo = Scene::STAGE;
	}
}

void TitleScene::Draw() {
	Novice::ScreenPrintf(0, 0, "Title Scene");
	Novice::ScreenPrintf(0, 30, "Push Tab");
}