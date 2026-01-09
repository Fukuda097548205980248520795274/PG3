#include "SelectUnitCommand.h"
#include "../../Selector/Selector.h"

/// @brief 実行
void SelectUnitCommand::Exec()
{
	selector_->SelectUnit();
}