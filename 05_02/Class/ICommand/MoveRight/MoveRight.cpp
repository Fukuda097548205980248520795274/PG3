#include "MoveRight.h"
#include "../../IObject/Selecter/Selecter.h"

/// @brief 実行
/// @param selector 
void MoveRight::Exec(Selector& selector)
{
	selector.MoveRight();
}