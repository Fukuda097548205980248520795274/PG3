#pragma once
#include "../IObject.h"

class Selector : public IObject
{
public:

	/// @brief コンストラクタ
	Selector();

	/// @brief 描画処理
	void Draw() override;


public:

	/// @brief 上に進む
	void MoveUp();

	/// @brief 左に進む
	void MoveLeft();

	/// @brief 下に進む
	void MoveDown();

	/// @brief 右に進む
	void MoveRight();


private:

	// 位置
	Vector2Int position_ = Vector2Int(0, 0);

	// 大きさ
	int size_ = 0;
};

