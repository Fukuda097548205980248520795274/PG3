#pragma once
#include "../ICommand.h"

class MoveLeftCommand : public ICommand
{
public:

	/// @brief 実行
	/// @param player 
	void Execute(Player* player) override;
};

