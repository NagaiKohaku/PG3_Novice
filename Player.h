#pragma once

#include "Bullet.h"
#include "BulletManager.h"
#include "Vector2.h"

///=====================================================/// 
/// プレイヤー
///=====================================================///
class Player {

	///-------------------------------------------/// 
	/// メンバ関数
	///-------------------------------------------///
public:

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	/// <param name="keys">キー情報</param>
	void Update(char* keys);

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
	/// <param name="keys">キー情報</param>
	void Move(char* keys);

	/// <summary>
	/// 攻撃
	/// </summary>
	/// <param name="keys">キー情報</param>
	void Attack(char* keys);

	///-------------------------------------------/// 
	/// ゲッター・セッター
	///-------------------------------------------///
public:

	/// <summary>
	/// バレットマネージャーのセッター
	/// </summary>
	/// <param name="ptr">バレットマネージャーのポインター</param>
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

	//移動速度
	float speed_;

	//最大クールタイム
	float maxCoolTime_;

	//時間
	float time_;

};