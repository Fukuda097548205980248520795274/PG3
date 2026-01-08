#include "MoveUp.h"
#include "../../IObject/Selecter/Selecter.h"

/// @brief 実行
/// @param selector 
void MoveUp::Exec(Selector& selector)
{
	selector.MoveUp();
}