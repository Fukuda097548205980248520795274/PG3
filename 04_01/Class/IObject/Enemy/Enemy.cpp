#include "Enemy.h"

#include <Novice.h>

/// @brief 更新処理
void Enemy::Update()
{
	// 位置を移動する
	position_ += velocity_;

	// 左右の両端で反転する
	if (position_.x + kRadius >= 1280.0f || position_.x - kRadius <= 0.0f) { velocity_.x *= -1.0f; }
}

/// @brief 描画処理
void Enemy::Draw()
{
	Novice::DrawEllipse(static_cast<int>(position_.x), static_cast<int>(position_.y),
		static_cast<int>(kRadius), static_cast<int>(kRadius), 0.0f, 0xFFFFFFFF, kFillModeSolid);
}