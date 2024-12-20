#pragma once

#include "Enemy.h"

#include "BulletManager.h"

#include "memory"
#include "list"

///=====================================================/// 
/// エネミーマネージャー
///=====================================================///
class EnemyManager {

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
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// エネミーの追加
	/// </summary>
	/// <param name="pos">座標</param>
	void AddEnemy(Vector2 pos);

	///-------------------------------------------/// 
	/// ゲッター・セッター
	///-------------------------------------------///
public:

	/// <summary>
	/// バレットマネージャーのセッター
	/// </summary>
	/// <param name="ptr">バレットマネージャーのポインター</param>
	void SetBulletManager(BulletManager* ptr) { bulletManager_ = ptr; }

	/// <summary>
	/// エネミーの数のゲッター
	/// </summary>
	/// <returns>エネミーの数</returns>
	size_t GetEnemyNum() { return enemies_.size(); }

	///-------------------------------------------/// 
	/// メンバ変数
	///-------------------------------------------///
private:

	//バレットマネージャー
	BulletManager* bulletManager_;

	//エネミーリスト
	std::list<std::unique_ptr<Enemy>> enemies_;
};