#include "SelectSceneInputHandler.h"
#include <cassert>
#include <Novice.h>

/// @brief 初期化
/// @param keys 
/// @param preKeys 
void SelectSceneInputHandler::Initialize(const char* keys, const char* preKeys)
{
	// nullptrチェック
	assert(keys);
	assert(preKeys);

	// 引数を受け取る
	keys_ = keys;
	preKeys_ = preKeys;
}

IStageSceneCommand* SelectSceneInputHandler::SelectorHandleInput(Selector* selector)
{
	(void)selector;
	return nullptr;
}

IStageSceneCommand* SelectSceneInputHandler::UnitHandleInput(Unit* unit)
{
	(void)unit;
	return nullptr;
}