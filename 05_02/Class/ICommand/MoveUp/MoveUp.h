#pragma once
#include "../ICommand.h"

class MoveUp : public ICommand
{
public:

	/// @brief 実行
	/// @param selector 
	void Exec(Selector& selector) override;
};

