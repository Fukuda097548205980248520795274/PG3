#include "SelectorMoveCommand.h"
#include "../../Selector/Selector.h"

/// @brief 実行
void SelectorMoveCommand::Exec()
{
	selector_->Move(x_, y_);
}