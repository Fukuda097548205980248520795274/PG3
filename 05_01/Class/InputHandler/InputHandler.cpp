#include "InputHandler.h"
#include <Novice.h>

#include "../ICommand/MoveLeftCommand/MoveLeftCommand.h"
#include "../ICommand/MoveRightCommand/MoveRightCommand.h"

/// @brief 入力ハンドルを取得する
/// @return 
ICommand* InputHandler::HandleInput()
{
	// Aキー
	if (Novice::CheckHitKey(DIK_A))return pressKeyA_.get();

	// Dキー
	if (Novice::CheckHitKey(DIK_D))return pressKeyD_.get();

	return nullptr;
}

/// @brief Dキーで右に進むコマンド
void InputHandler::AssignMoveRightCommand2PressKeyD()
{
	pressKeyD_ = std::make_unique<MoveRightCommand>();
}

/// @brief Aキーで左に進むコマンド
void InputHandler::AssignMoveLeftCommand2PressKeyA()
{
	pressKeyA_ = std::make_unique<MoveLeftCommand>();
}