#include "UnitMoveCommand.h"
#include "../../Unit/Unit.h"

/// @brief 実行
void UnitMoveCommand::Exec()
{
	unit_->Move(x_, y_);
}