#pragma once
#include "IScene.h"

#include "Player.h"
#include "EnemyManager.h"
#include "BulletManager.h"

#include "memory"

/// <summary>
/// ISceneクラスを継承したStageSceneを宣言
/// </summary>
class StageScene : public IScene {
public://メンバ関数

	///初期化処理
	void Initialize() override;

	///更新処理
	void Update(char* keys, char* preKeys) override;

	///描画処理
	void Draw() override;

private:

	//プレイヤー
	std::unique_ptr<Player> player_;

	//エネミーマネージャー
	std::unique_ptr<EnemyManager> enemyManager_;

	//バレットマネージャー
	std::unique_ptr<BulletManager> bulletManager_;

};