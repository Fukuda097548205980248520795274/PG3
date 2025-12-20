#pragma once
#include "../IScene.h"
#include <memory>

#include "../../IObject/Player/Player.h"
#include "../../IObject/Bullet/Bullet.h"
#include "../../IObject/Enemy/Enemy.h"
#include "../../IObject/Bg/Bg.h"

class StageScene : public IScene
{
public:

	/// @brief 初期化
	void Initialize() override;

	/// @brief 更新処理
	void Update() override;

	/// @brief 描画処理
	void Draw() override;


private:

	// プレイヤー
	std::unique_ptr<Player> player_ = nullptr;

	// 弾
	std::unique_ptr<Bullet> bullet_ = nullptr;

	// 敵
	std::unique_ptr<Enemy> enemy_ = nullptr;


private:

	// 背景
	std::unique_ptr<Bg> bg_ = nullptr;
};

