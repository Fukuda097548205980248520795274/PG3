#include "StageScene.h"

/// @brief 初期化
void StageScene::Initialize()
{
	// グリッドの生成
	grid_ = std::make_unique<Grid>();

	// セレクターの生成
	selector_ = std::make_unique<Selector>();
}

/// @brief 更新処理
void StageScene::Update()
{
	
}

/// @brief 描画処理
void StageScene::Draw()
{
	grid_->Draw();

	// セレクターの描画
	selector_->Draw();
}