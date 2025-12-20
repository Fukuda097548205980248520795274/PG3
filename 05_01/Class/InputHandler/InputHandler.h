#pragma once
#include "../ICommand/ICommand.h"
#include <memory>

class InputHandler
{
public:

	/// @brief 入力ハンドルを取得する
	/// @return 
	ICommand* HandleInput();

	/// @brief Dキーで右に進むコマンド
	void AssignMoveRightCommand2PressKeyD();

	/// @brief Aキーで左に進むコマンド
	void AssignMoveLeftCommand2PressKeyA();


private:

	// 右移動コマンド
	std::unique_ptr<ICommand> pressKeyD_ = nullptr;

	// 左移動コマンド
	std::unique_ptr<ICommand> pressKeyA_ = nullptr;
};

