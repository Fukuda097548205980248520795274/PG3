#include "Stage.h"

/// @brief 初期化
void Stage::Initialize()
{
	// 弾の生成と初期化
	bullet_ = std::make_unique<Bullet>();

	// プレイヤーの生成と初期化
	player_ = std::make_unique<Player>(Vector2(640.0f, 580.0f));
	player_->InputOption(inputManager_.get());
	player_->SetShotFunc([&](const Vector2& position) {bullet_->Shot(position); });

	// 敵の生成と初期化
	enemy_ = std::make_unique<Enemy>(Vector2(640.0f, 40.0f));
}

/// @brief 更新処理
void Stage::Update()
{
	// 入力マネージャの更新
	inputManager_->Update();

	// プレイヤーの更新
	player_->Update();

	// 弾の更新
	bullet_->Update();

	// 敵の更新処理
	enemy_->Update();

	// 入力の判定
	inputManager_->InputCheck();
}

/// @brief 描画処理
void Stage::Draw()
{
	// 弾の描画
	bullet_->Draw();

	// プレイヤーの描画
	player_->Draw();

	// 敵の描画
	enemy_->Draw();
}