#pragma once
#include <vector>
#include <memory>
#include <list>
#include "../Unit/Unit.h"

class Selector
{
public:

	/// @brief コンストラクタ
	/// @param x 
	/// @param y 
	Selector(int x, int y) : mapX_(x), mapY_(y){}

	/// @brief 初期化
	void Initialize();

	/// @brief 更新処理
	void Update();

	/// @brief 描画処理
	void Draw();


	/// @brief ユニットモードかどうか
	/// @return 
	bool IsUnitMode()const { return selectedUnit_ != nullptr; }

	/// @brief undoカウントを取得する
	/// @return 
	int GetUndoCount()const { return undoCount_; }


	/// @brief 移動
	/// @param x 
	/// @param y 
	void Move(int x, int y);

	/// @brief ユニットを選択or解除
	void SelectOrCancellationUnit();

	/// @brief 巻き戻す
	void Undo();


private:

	int mapX_ = 0;
	int mapY_ = 0;

	/// @brief マップサイズ
	int mapSize_ = 32;


private:

	// undo用カウンター
	int undoCount_ = 0;

	std::list<std::pair<int, int>> undoList_;

	/// @brief undo用移動関数
	/// @param x 
	/// @param y 
	void UndoMove(int x, int y);


private:

	// ユニットの配列
	std::vector<std::unique_ptr<Unit>> units_;

	// 選ばれたユニット
	Unit* selectedUnit_ = nullptr;
};

