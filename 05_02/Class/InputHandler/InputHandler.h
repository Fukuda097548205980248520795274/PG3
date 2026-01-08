#pragma once
#include <memory>
#include "../ICommand/ICommand.h"

class InputHandler
{
public:

	ICommand* HandleInput(const char* key, const char* preKey);

	/// @brief Wキー : 上に進む
	void AssignMoveUpCommandTriggerKeyW();
	
	/// @brief Aキー : 左に進む
	void AssignMoveLeftCommandTriggerKeyA();

	/// @brief Sキー : 下に進む
	void AssignMoveDownCommandTriggerKeyS();

	/// @brief Dキー : 右に進む
	void AssignMoveRightCommandTriggerKeyD();


private:

	std::unique_ptr<ICommand> triggerKeyW_ = nullptr;
	std::unique_ptr<ICommand> triggerKeyA_ = nullptr;
	std::unique_ptr<ICommand> triggerKeyS_ = nullptr;
	std::unique_ptr<ICommand> triggerKeyD_ = nullptr;
};

