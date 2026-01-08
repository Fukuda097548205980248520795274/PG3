#include "Selecter.h"
#include <Novice.h>

/// @brief コンストラクタ
Selector::Selector()
{
	// サイズを求める
	size_ = 1280 / kMoveRangeWidth;
}

/// @brief 描画処理
void Selector::Draw()
{
	Novice::DrawBox(position_.x * size_, position_.y * size_,
		position_.x * size_ + size_, position_.y * size_ + size_, 0.0f, 0xFF0000FF, kFillModeWireFrame);
}



/// @brief 上に進む
void Selector::MoveUp()
{
	if (position_.y <= 0)return;

	position_.y--;
}

/// @brief 左に進む
void Selector::MoveLeft()
{
	if (position_.x <= 0)return;

	position_.x--;
}

/// @brief 下に進む
void Selector::MoveDown()
{
	if (position_.y >= kMoveRangeHeight)return;

	position_.y++;
}

/// @brief 右に進む
void Selector::MoveRight()
{
	if (position_.x >= kMoveRangeWidth)return;

	position_.x++;
}