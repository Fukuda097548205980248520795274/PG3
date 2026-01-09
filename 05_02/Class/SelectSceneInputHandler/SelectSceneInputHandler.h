#pragma once
#include "../IStageSceneCommand/IStageSceneCommand.h"
#include <memory>

#include "../IStageSceneCommand/SelectorMoveCommand/SelectorMoveCommand.h"
#include "../IStageSceneCommand/SelectUnitCommand/SelectUnitCommand.h"
#include "../IStageSceneCommand/UnitMoveCommand/UnitMoveCommand.h"
#include "../IStageSceneCommand/UnitMoveEndCommand/UnitMoveEndCommand.h"

class Selector;
class Unit;

class SelectSceneInputHandler
{
public:

	/// @brief 初期化
	/// @param keys 
	/// @param preKeys 
	void Initialize(const char* keys, const char* preKeys);

	IStageSceneCommand* SelectorHandleInput(Selector* selector);

	IStageSceneCommand* UnitHandleInput(Unit* unit);

private:

	const char* keys_ = nullptr;

	const char* preKeys_ = nullptr;


private:

	std::unique_ptr<SelectorMoveCommand> selectorMoveUp_ = nullptr;
	std::unique_ptr<SelectorMoveCommand> selectorMoveLeft_ = nullptr;
	std::unique_ptr<SelectorMoveCommand> selectorMoveDown_ = nullptr;
	std::unique_ptr<SelectorMoveCommand> selectorMoveRight_ = nullptr;

	std::unique_ptr<SelectUnitCommand> selectUnit_ = nullptr;

	std::unique_ptr<UnitMoveCommand> unitMoveUp_ = nullptr;
	std::unique_ptr<UnitMoveCommand> unitMoveLeft_ = nullptr;
	std::unique_ptr<UnitMoveCommand> unitMoveDown_ = nullptr;
	std::unique_ptr<UnitMoveCommand> unitMoveRight_ = nullptr;

	std::unique_ptr<UnitMoveEndCommand> unitMoveEnd_ = nullptr;
};

