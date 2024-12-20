#include "Enemy.h"

#include "Novice.h"

#include "cmath"

///=====================================================/// 
/// 初期化
///=====================================================///
void Enemy::Initialize(Vector2 pos) {

	//座標の初期化
	pos_ = pos;

	//半径の初期化
	radius_ = 25.0f;
}

///=====================================================/// 
/// 更新
///=====================================================///
void Enemy::Update() {

	//当たり判定
	HitCheck();
}

///=====================================================/// 
/// 描画
///=====================================================///
void Enemy::Draw() {

	//円で描画
	Novice::DrawEllipse(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		static_cast<int>(radius_),
		static_cast<int>(radius_),
		0.0f,
		RED,
		kFillModeSolid
	);
}

///=====================================================/// 
/// 当たり判定
///=====================================================///
void Enemy::HitCheck() {

	//バレットリストを取得
	std::list<Bullet*> bullets_ = bulletManager_->GetBulletList();

	//バレットリストの全要素を参照
	for (auto& bullet : bullets_) {

		//バレットとエネミーの差分ベクトル
		Vector2 bullet2Enemy = pos_ - bullet->GetPos();

		//バレットとエネミーの距離
		float bullet2EnemyLength = sqrtf(powf(bullet2Enemy.x, 2.0f) + powf(bullet2Enemy.y, 2.0f));

		//バレットとエネミーが接していたら
		if (radius_ + bullet->GetRadius() >= bullet2EnemyLength) {

			//エネミーの死亡フラグをtrueにする
			isDead_ = true;

			//バレットの死亡フラグをtrueにする
			bullet->SetIsDead(true);
		}
	}
}