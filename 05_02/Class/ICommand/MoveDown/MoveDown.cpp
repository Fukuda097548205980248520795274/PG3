#include "MoveDown.h"
#include "../../IObject/Selecter/Selecter.h"

/// @brief 実行
/// @param selector 
void MoveDown::Exec(Selector& selector)
{
	selector.MoveDown();
}