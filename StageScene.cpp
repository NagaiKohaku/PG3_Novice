#include "StageScene.h"

void StageScene::Initialize() {

	/// === バレットマネージャー === ///

	//生成
	bulletManager_ = std::make_unique<BulletManager>();

	//初期化
	bulletManager_->Initialize();

	/// === エネミーマネージャー === ///

	//生成
	enemyManager_ = std::make_unique<EnemyManager>();

	//初期化
	enemyManager_->Initialize();

	//バレットマネージャーのセット
	enemyManager_->SetBulletManager(bulletManager_.get());

	//エネミーを追加
	enemyManager_->AddEnemy({ 540.0f,260.0f });

	//エネミーを追加
	enemyManager_->AddEnemy({ 740.0f,260.0f });

	/// === プレイヤー === ///

	//生成
	player_ = std::make_unique<Player>();

	//初期化
	player_->Initialize();

	//バレットマネージャーのセット
	player_->SetBulletManager(bulletManager_.get());

}

void StageScene::Update(char* keys, char* preKeys) {

	//プレイヤーの更新
	player_->Update(keys);

	//エネミーマネージャーの更新
	enemyManager_->Update();

	//バレットマネージャーの更新
	bulletManager_->Update();

	//敵の数が0になった時
	if (enemyManager_->GetEnemyNum() <= 0) {
		//シーンをCLEARに切り替える
		sceneNo = Scene::CLEAR;
	}

	//タブキーを押した瞬間
	if (keys[DIK_TAB] && preKeys[DIK_TAB] == false) {
		//シーンをCLEARに切り替える
		sceneNo = Scene::CLEAR;
	}
}

void StageScene::Draw() {
	Novice::ScreenPrintf(0, 0, "Stage Scene");
	Novice::ScreenPrintf(0, 30, "Push Tab or Eliminate Enemy");

	//プレイヤーの描画
	player_->Draw();

	//エネミーマネージャーの描画
	enemyManager_->Draw();

	//バレットマネージャーの描画
	bulletManager_->Draw();

}