#include "Unit.h"
#include <Novice.h>

/// @brief 初期化
void Unit::Initialize()
{

}

/// @brief 更新処理
void Unit::Update()
{

}

/// @brief 描画処理
void Unit::Draw()
{
	Novice::DrawBox(mapX_ * 32 + 4, mapY_ * 32 + 4, mapSize_, mapSize_, 0.0f, 0xFFFFFFF, kFillModeSolid);
}

/// @brief 移動
/// @param x 
/// @param y 
void Unit::Move(int x, int y)
{
	mapX_ += x;
	mapY_ += y;
}

/// @brief 移動をやめる
void Unit::MoveEnd()
{

}