#include "StageScene.h"

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
	// セレクターの描画
	selector_->Draw();
}