#include "StageScene.h"
#include <Novice.h>

/// @brief 初期化
void StageScene::Initialize()
{
	// セレクターの生成と初期化
	selector_ = std::make_unique<Selector>(2, 2);
	selector_->Initialize();
}

/// @brief 更新処理
void StageScene::Update()
{
	// セレクターの更新
	selector_->Update();
}

/// @brief 描画処理
void StageScene::Draw()
{
	for (int i = 0; i <= 40; ++i)
	{
		Novice::DrawLine(i * 32, 0, i * 32, 640, 0xFFFFFFFF);
	}

	for (int i = 0; i <= 20; ++i)
	{
		Novice::DrawLine(0, i * 32, 1280, i * 32, 0xFFFFFFFF);
	}

	Novice::DrawBox(0, 640, 1280, 80, 0.0f, 0x000000FF, kFillModeSolid);

	// セレクターの描画
	selector_->Draw();
}