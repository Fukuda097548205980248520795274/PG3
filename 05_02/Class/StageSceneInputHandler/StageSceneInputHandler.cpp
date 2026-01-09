#include "StageSceneInputHandler.h"
#include <cassert>
#include <Novice.h>

/// @brief 初期化
/// @param keys 
/// @param preKeys 
void StageSceneInputHandler::Initialize(Selector* selector)
{
	// nullptrチェック
	assert(selector);

	// コマンド生成
	selectorMoveUp_ = std::make_unique<SelectorMoveCommand>(selector, 0, -1);
	selectorMoveLeft_ = std::make_unique<SelectorMoveCommand>(selector, -1, 0);
	selectorMoveDown_ = std::make_unique<SelectorMoveCommand>(selector, 0, 1);
	selectorMoveRight_ = std::make_unique<SelectorMoveCommand>(selector, 1, 0);
	selectOrCancellationUnit_ = std::make_unique<SelectOrCancellationUnitUnitCommand>(selector);
}

IStageSceneCommand* StageSceneInputHandler::HandleInput(const char* keys, const char* preKeys)
{
	if (keys == nullptr || preKeys == nullptr)return nullptr;;

	if (keys[DIK_W] && !preKeys[DIK_W])
	{
		return selectorMoveUp_.get();
	}

	if (keys[DIK_A] && !preKeys[DIK_A])
	{
		return selectorMoveLeft_.get();
	}

	if (keys[DIK_S] && !preKeys[DIK_S])
	{
		return selectorMoveDown_.get();
	}

	if (keys[DIK_D] && !preKeys[DIK_D])
	{
		return selectorMoveRight_.get();
	}

	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE])
	{
		return selectOrCancellationUnit_.get();
	}

	return nullptr;
}