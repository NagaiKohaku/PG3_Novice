#pragma once

#include "Vector2.h"

///=====================================================/// 
/// バレット
///=====================================================///
class Bullet {

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
	/// 移動
	/// </summary>
	void Move();

	///-------------------------------------------/// 
	/// ゲッター・セッター
	///-------------------------------------------///
public:

	/// <summary>
	/// 座標のゲッター
	/// </summary>
	/// <returns>座標</returns>
	Vector2 GetPos() { return pos_; }

	/// <summary>
	/// 半径のゲッター
	/// </summary>
	/// <returns>半径</returns>
	float GetRadius() { return radius_; }

	/// <summary>
	/// 死亡フラグのゲッター
	/// </summary>
	/// <returns>フラグ</returns>
	bool GetIsDead() { return isDead_; }

	/// <summary>
	/// 死亡フラグのセッター
	/// </summary>
	/// <param name="flag">フラグ</param>
	void SetIsDead(bool flag) { isDead_ = flag; }

	///-------------------------------------------/// 
	/// メンバ変数
	///-------------------------------------------///
private:

	//座標
	Vector2 pos_;

	//半径
	float radius_;

	//移動速度
	float speed_;

	//死亡フラグ
	bool isDead_;

	//生存時間
	float maxLifeTime_;

	//時間
	float time_;
};

