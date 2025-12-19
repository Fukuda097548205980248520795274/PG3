#include "Clear.h"

/// @brief 初期化
void Clear::Initialize()
{

}

/// @brief 更新処理
void Clear::Update()
{
	// 入力マネージャの更新
	inputManager_->Update();


	// 入力の判定
	inputManager_->InputCheck();
}

/// @brief 描画処理
void Clear::Draw()
{

}