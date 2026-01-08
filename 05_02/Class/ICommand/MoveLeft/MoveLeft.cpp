#include "MoveLeft.h"
#include "../../IObject/Selecter/Selecter.h"

/// @brief 実行
/// @param selector 
void MoveLeft::Exec(Selector& selector)
{
	selector.MoveLeft();
}