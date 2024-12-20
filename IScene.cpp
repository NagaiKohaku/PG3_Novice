#include "IScene.h"

//シーンはタイトルで初期化
int IScene::sceneNo = Scene::TITLE;

//仮想デストラクタ定義
IScene::~IScene() {}

//シーン番号ゲッター
int IScene::GetSceneNo() { return sceneNo; }