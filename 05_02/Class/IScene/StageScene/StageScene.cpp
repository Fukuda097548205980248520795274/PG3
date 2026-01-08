#include "StageScene.h"

/// @brief 初期化
void StageScene::Initialize()
{
	// 入力ハンドラの生成
	inputHandler_ = std::make_unique<InputHandler>();
	inputHandler_->AssignMoveUpCommandTriggerKeyW();
	inputHandler_->AssignMoveLeftCommandTriggerKeyA();
	inputHandler_->AssignMoveDownCommandTriggerKeyS();
	inputHandler_->AssignMoveRightCommandTriggerKeyD();

	// グリッドの生成
	grid_ = std::make_unique<Grid>();

	// セレクターの生成
	selector_ = std::make_unique<Selector>();
}

/// @brief 更新処理
void StageScene::Update(const char* key , const char* preKey)
{
	ICommand* command = inputHandler_->HandleInput(key, preKey);
	if (command)
	{
		command->Exec(*selector_);
	}
}

/// @brief 描画処理
void StageScene::Draw()
{
	grid_->Draw();

	// セレクターの描画
	selector_->Draw();
}