#include "StageScene.h"

/// @brief 初期化
void StageScene::Initialize()
{
	// 入力ハンドルの生成と設定
	inputHandler_ = std::make_unique<InputHandler>();
	inputHandler_->AssignMoveLeftCommand2PressKeyA();
	inputHandler_->AssignMoveRightCommand2PressKeyD();

	// プレイヤーの生成と初期化
	player_ = std::make_unique<Player>(Vector2(640.0f, 360.0f));
}

/// @brief 更新処理
void StageScene::Update()
{
	// プレイヤーの更新
	player_->Update();

	// 入力ハンドルのコマンドを取得する
	ICommand* command = inputHandler_->HandleInput();
	if (command)
	{
		command->Execute(player_.get());
	}
}

/// @brief 描画処理
void StageScene::Draw()
{
	// プレイヤーの描画
	player_->Draw();
}