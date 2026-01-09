#pragma once

class Selector;

class IStageSceneCommand
{
public:

	/// @brief 仮想デストラクタ
	virtual ~IStageSceneCommand() = default;

	/// @brief 実行
	/// @param selector セレクター
	/// @param unit ユニット
	virtual void Exec() = 0;
};

/// @brief セレクター移動コマンド
class SelectorMoveCommand : public IStageSceneCommand
{
public:

	/// @brief コンストラクタ
	/// @param selector セレクター
	/// @param x 
	/// @param y 
	SelectorMoveCommand(Selector* selector, int x, int y) : selector_(selector), x_(x), y_(y) {}

	/// @brief 実行
	void Exec() override;


private:

	/// @brief セレクター
	Selector* selector_ = nullptr;

	int x_;
	int y_;
};

/// @brief ユニット選択or解除コマンド
class SelectOrCancellationUnitUnitCommand : public IStageSceneCommand
{
public:

	/// @brief コンストラクタ
	/// @param selector 
	SelectOrCancellationUnitUnitCommand(Selector* selector) : selector_(selector) {}

	/// @brief 実行
	void Exec() override;


private:

	/// @brief セレクター
	Selector* selector_ = nullptr;
};

class UndoCommand : public IStageSceneCommand
{
public:

	/// @brief コンストラクタ
	/// @param selector 
	UndoCommand(Selector* selector) : selector_(selector) {}

	/// @brief 実行
	void Exec() override;


private:

	/// @brief セレクター
	Selector* selector_ = nullptr;
};