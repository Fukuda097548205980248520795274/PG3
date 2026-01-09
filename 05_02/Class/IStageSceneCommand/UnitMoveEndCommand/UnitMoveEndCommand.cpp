#include "UnitMoveEndCommand.h"
#include "../../Unit/Unit.h"

/// @brief 実行
void UnitMoveEndCommand::Exec()
{
	unit_->MoveEnd();
}