#pragma once
#include "../IStageSceneCommand.h"

class Selector;

class SelectUnitCommand : public IStageSceneCommand
{
public:

	/// @brief コンストラクタ
	/// @param selector 
	SelectUnitCommand(Selector* selector) : selector_(selector){}

	/// @brief 実行
	void Exec() override;


private:

	/// @brief セレクター
	Selector* selector_ = nullptr;
};

