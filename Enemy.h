#pragma once

#include "Bullet.h"
#include "BulletManager.h"
#include "Vector2.h"

///=====================================================/// 
/// エネミー
///=====================================================///
class Enemy {

	///-------------------------------------------/// 
	/// メンバ関数
	///-------------------------------------------///
public:

	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="pos">座標</param>
	void Initialize(Vector2 pos);

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	///-------------------------------------------///
	/// クラス内関数
	///-------------------------------------------///
private:

	/// <summary>
	/// 当たり判定
	/// </summary>
	void HitCheck();

	///-------------------------------------------/// 
	/// ゲッター・セッター
	///-------------------------------------------///
public:

	/// <summary>
	/// 死亡フラグのゲッター
	/// </summary>
	/// <returns>フラグ</returns>
	bool GetIsDead() { return isDead_; }

	/// <summary>
	/// バレットマネージャーのセッター
	/// </summary>
	/// <param name="ptr">マネージャーのポインター</param>
	void SetBulletManager(BulletManager* ptr) { bulletManager_ = ptr; }

	///-------------------------------------------/// 
	/// メンバ変数
	///-------------------------------------------///
private:

	//バレットマネージャー
	BulletManager* bulletManager_;

	//座標
	Vector2 pos_;

	//半径
	float radius_;

	//死亡フラグ
	bool isDead_;
};