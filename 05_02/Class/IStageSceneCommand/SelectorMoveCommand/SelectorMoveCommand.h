#pragma once
#include "../IStageSceneCommand.h"

class Selector;

class SelectorMoveCommand : public IStageSceneCommand
{
public:

	/// @brief コンストラクタ
	/// @param selector セレクター
	/// @param x 
	/// @param y 
	SelectorMoveCommand(Selector* selector, int x, int y) : selector_(selector) , x_(x) , y_(y){}

	/// @brief 実行
	void Exec() override;


private:

	/// @brief セレクター
	Selector* selector_ = nullptr;

	int x_;
	int y_;
};

