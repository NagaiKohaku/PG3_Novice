#include "EnemyManager.h"

///=====================================================/// 
/// 初期化
///=====================================================///
void EnemyManager::Initialize() {

	//エネミーリストのクリア
	enemies_.clear();
}

///=====================================================/// 
/// 更新
///=====================================================///
void EnemyManager::Update() {

	//エネミーの消滅処理
	enemies_.remove_if([](std::unique_ptr<Enemy>& enemy) {

		//エネミーの死亡フラグがtrueだったら
		if (enemy->GetIsDead()) {

			//エネミーの解放
			enemy.reset();

			return true;
		}

		return false;
		});

	//エネミーリストの全要素の更新
	for (auto& enemy : enemies_) {

		enemy->Update();
	}
}

///=====================================================/// 
/// 描画
///=====================================================///
void EnemyManager::Draw() {

	//エネミーリストの全要素の描画
	for (auto& enemy : enemies_) {

		enemy->Draw();
	}
}

///=====================================================/// 
/// エネミーの追加
///=====================================================///
void EnemyManager::AddEnemy(Vector2 pos) {

	//追加する新しいエネミー
	std::unique_ptr<Enemy> newEnemy = std::make_unique<Enemy>();

	//エネミーの初期化
	newEnemy->Initialize(pos);

	//バレットマネージャーをセット
	newEnemy->SetBulletManager(bulletManager_);

	//エネミーリストの追加
	enemies_.push_back(std::move(newEnemy));

}