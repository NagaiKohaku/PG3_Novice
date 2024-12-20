#include "BulletManager.h"

///=====================================================/// 
/// 初期化
///=====================================================///
void BulletManager::Initialize() {

	//バレットリストのクリア
	bullets_.clear();
}

///=====================================================/// 
/// 更新
///=====================================================///
void BulletManager::Update() {

	//バレットの消滅処理
	bullets_.remove_if([](std::unique_ptr<Bullet>& bullet) {

		//バレットの死亡フラグがtrueだったら
		if (bullet->GetIsDead()) {

			//バレットを解放
			bullet.reset();

			return true;
		}

		return false;
		});

	//バレットリストの全要素の更新
	for (auto& bullet : bullets_) {

		bullet->Update();
	}
}

///=====================================================/// 
/// 描画
///=====================================================///
void BulletManager::Draw() {

	//バレットリストの全要素の描画
	for (auto& bullet : bullets_) {

		bullet->Draw();
	}
}

///=====================================================/// 
/// バレットの追加
///=====================================================///
void BulletManager::AddBullet(Vector2 pos) {

	//追加する新しいバレット
	std::unique_ptr<Bullet> newBullet = std::make_unique<Bullet>();

	//新しいバレットの初期化
	newBullet->Initialize(pos);

	//バレットリストの追加
	bullets_.push_back(std::move(newBullet));
}

///=====================================================/// 
/// バレットリストのゲッター
///=====================================================///
std::list<Bullet*> BulletManager::GetBulletList() {

	//返すためのリスト
	std::list<Bullet*> newList;

	//バレットリストの全要素を参照
	for (auto& bullet : bullets_) {

		//返り値のリストにバレットをプッシュバック
		newList.push_back(bullet.get());
	}

	//リストを返す
	return newList;
}
