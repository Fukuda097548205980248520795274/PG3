#include "StageScene.h"

/// @brief 初期化
void StageScene::Initialize()
{
	// 弾の生成と初期化
	bullet_ = std::make_unique<Bullet>();

	// プレイヤーの生成と初期化
	player_ = std::make_unique<Player>(Vector2(640.0f, 580.0f));
	player_->InputOption(inputManager_.get());
	player_->SetShotFunc([&](const Vector2& position) {bullet_->Shot(position); });

	// 敵の生成と初期化
	enemy_ = std::make_unique<Enemy>(Vector2(640.0f, 40.0f));

	// 背景の生成
	bg_ = std::make_unique<Bg>("./Resources/bg.png");
}

/// @brief 更新処理
void StageScene::Update()
{
	// 入力マネージャの更新
	inputManager_->Update();

	// プレイヤーの更新
	player_->Update();

	// 弾の更新
	bullet_->Update();

	// 敵の更新処理
	enemy_->Update();

	// 背景の更新処理
	bg_->Update();

	// 入力の判定
	inputManager_->InputCheck();


	if (!enemy_->IsFinished())
	{
		if (bullet_->GetRadius() + enemy_->GetRadius() >=
			(bullet_->GetPosition() - enemy_->GetPosition()).Length())
		{
			bullet_->OnCollision();
			enemy_->OnCollision();
		}
	}


	// 敵が終了したら、クリアシーンに移る
	if (enemy_->IsFinished())
	{
		sceneNo = SCENE::CLEAR;
	}
}

/// @brief 描画処理
void StageScene::Draw()
{
	// 背景の描画
	bg_->Draw();

	// 弾の描画
	bullet_->Draw();

	// プレイヤーの描画
	player_->Draw();

	// 敵の描画
	enemy_->Draw();

	Novice::ScreenPrintf(0, 0, "Stage_Scene");
}