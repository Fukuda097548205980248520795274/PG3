#pragma once
#include "../ICommand.h"

class MoveRight : public ICommand
{
public:

	/// @brief 実行
	/// @param selector 
	void Exec(Selector& selector) override;
};

