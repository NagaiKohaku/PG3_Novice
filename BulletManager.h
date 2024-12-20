#pragma once

#include "Bullet.h"

#include "memory"
#include "list"

///=====================================================/// 
/// バレットマネージャー
///=====================================================///
class BulletManager {

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
	/// バレットの追加
	/// </summary>
	/// <param name="pos">生成座標</param>
	void AddBullet(Vector2 pos);

	///-------------------------------------------/// 
	/// ゲッター・セッター
	///-------------------------------------------///
public:

	/// <summary>
	/// バレットリストのゲッター
	/// </summary>
	/// <returns>バレットリスト</returns>
	std::list<Bullet*> GetBulletList();

	///-------------------------------------------/// 
	/// メンバ変数
	///-------------------------------------------///
private:

	//バレットリスト
	std::list<std::unique_ptr<Bullet>> bullets_;
};