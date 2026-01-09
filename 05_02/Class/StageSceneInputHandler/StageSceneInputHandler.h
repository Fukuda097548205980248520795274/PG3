#pragma once
#include "../IStageSceneCommand/IStageSceneCommand.h"
#include <memory>

class Selector;

class StageSceneInputHandler
{
public:

	/// @brief 初期化
	/// @param keys 
	/// @param preKeys 
	void Initialize(Selector* selector);

	/// @brief 入力コマンドのハンドルを取得する
	/// @param keys 
	/// @param preKeys 
	/// @return 
	IStageSceneCommand* HandleInput(const char* keys, const char* preKeys);


private:

	std::unique_ptr<SelectorMoveCommand> selectorMoveUp_ = nullptr;
	std::unique_ptr<SelectorMoveCommand> selectorMoveLeft_ = nullptr;
	std::unique_ptr<SelectorMoveCommand> selectorMoveDown_ = nullptr;
	std::unique_ptr<SelectorMoveCommand> selectorMoveRight_ = nullptr;

	std::unique_ptr<SelectOrCancellationUnitUnitCommand> selectOrCancellationUnit_ = nullptr;
};

