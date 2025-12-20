#include "MoveRightCommand.h"
#include "../../IObject/Player/Player.h"

/// @brief 実行
/// @param player 
void MoveRightCommand::Execute(Player* player)
{
	// 右に進む
	player->MoveRight();
}