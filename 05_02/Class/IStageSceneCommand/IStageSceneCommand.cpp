#include "IStageSceneCommand.h"
#include "../Selector/Selector.h"

/// @brief 実行
void SelectorMoveCommand::Exec()
{
	selector_->Move(x_, y_);
}

/// @brief 実行
void SelectOrCancellationUnitUnitCommand::Exec()
{
	selector_->SelectOrCancellationUnit();
}