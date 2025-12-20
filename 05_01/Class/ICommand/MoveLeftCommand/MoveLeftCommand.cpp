#include "MoveLeftCommand.h"
#include "../../IObject/Player/Player.h"

/// @brief 実行
/// @param player 
void MoveLeftCommand::Execute(Player* player)
{
	// 左に進む
	player->MoveLeft();
}