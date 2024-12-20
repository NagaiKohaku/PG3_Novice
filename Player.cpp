#include "Player.h"

#include "Novice.h"

///=====================================================/// 
/// 初期化
///=====================================================///
void Player::Initialize() {

	//座標の初期化
	pos_ = { 640.0f,360.0f };

	//半径の初期化
	radius_ = 25.0f;

	//移動速度の初期化
	speed_ = 6.0f;

	//最大クールタイムの初期化
	maxCoolTime_ = 0.1f;

	//時間の初期化
	time_ = 0.0f;
}

///=====================================================/// 
/// 更新
///=====================================================///
void Player::Update(char* keys) {

	//時間を進める
	time_ += 1.0f / 60.0f;

	//移動
	Move(keys);

	//攻撃
	Attack(keys);
}

///=====================================================/// 
/// 描画
///=====================================================///
void Player::Draw() {

	//円で描画
	Novice::DrawEllipse(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		static_cast<int>(radius_),
		static_cast<int>(radius_),
		0.0f,
		WHITE,
		kFillModeSolid
	);
}

///=====================================================/// 
/// 移動	
///=====================================================///
void Player::Move(char* keys) {

	//Dキーが押されたら
	if (keys[DIK_D]) {

		//左へ移動
		pos_.x += speed_;
	}

	//Aキーが押されたら
	if (keys[DIK_A]) {

		//右へ移動
		pos_.x -= speed_;
	}

	//Sキーが押されたら
	if (keys[DIK_S]) {

		//下に移動
		pos_.y += speed_;
	}

	//Wキーが押されたら
	if (keys[DIK_W]) {

		//上へ移動
		pos_.y -= speed_;
	}
}

///=====================================================/// 
/// 攻撃
///=====================================================///
void Player::Attack(char* keys) {

	//時間がクールタイムを越えていたら
	if (time_ >= maxCoolTime_) {

		//スペースキーが押されていたら
		if (keys[DIK_SPACE]) {

			//バレットを追加
			bulletManager_->AddBullet(pos_);

			//時間のリセット
			time_ = 0.0f;
		}
	}
}