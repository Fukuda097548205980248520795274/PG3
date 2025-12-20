#pragma once

class Player;

class ICommand
{
public:

	/// @brief 仮想デストラクタ
	virtual ~ICommand() = default;

	/// @brief 実行
	/// @param player 
	virtual void Execute(Player* player) = 0;
};

