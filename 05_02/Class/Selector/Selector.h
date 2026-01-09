#pragma once
#include <vector>
#include <memory>
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


	/// @brief 移動
	/// @param x 
	/// @param y 
	void Move(int x, int y);

	/// @brief ユニットを選択or解除
	void SelectOrCancellationUnit();


private:

	int mapX_ = 0;
	int mapY_ = 0;

	/// @brief マップサイズ
	int mapSize_ = 32;


private:

	// ユニットの配列
	std::vector<std::unique_ptr<Unit>> units_;

	// 選ばれたユニット
	Unit* selectedUnit_ = nullptr;
};

