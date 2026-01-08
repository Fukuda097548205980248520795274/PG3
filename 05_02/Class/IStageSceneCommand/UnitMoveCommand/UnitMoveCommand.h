#pragma once
#include "../IStageSceneCommand.h"

class Unit;

class UnitMoveCommand : public IStageSceneCommand
{
public:

	/// @brief コンストラクタ
	/// @param unit ユニット
	/// @param x 
	/// @param y 
	UnitMoveCommand(Unit* unit , int x, int y) : unit_(unit) , x_(x) , y_(y){}

	/// @brief 実行
	void Exec() override;


private:

	/// @brief ユニット
	Unit* unit_ = nullptr;

	int x_;
	int y_;
};

