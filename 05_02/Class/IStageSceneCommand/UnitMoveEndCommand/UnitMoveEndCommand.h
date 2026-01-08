#pragma once
#include "../IStageSceneCommand.h"

class Unit;
class Selector;

class UnitMoveEndCommand : public IStageSceneCommand
{
public:

	/// @brief コンストラクタ
	/// @param unit ユニット
	/// @param selector セレクター
	UnitMoveEndCommand(Unit* unit, Selector* selector) : unit_(unit) , selector_(selector){}

	/// @brief 実行
	void Exec() override;


private:

	/// @brief ユニット
	Unit* unit_ = nullptr;

	/// @brief セレクター
	Selector* selector_ = nullptr;
};

