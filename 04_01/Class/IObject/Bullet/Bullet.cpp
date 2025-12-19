#include "Bullet.h"

#include <Novice.h>

/// @brief 更新処理
void Bullet::Update()
{
	// 発射中のみ処理する
	if (!isShot_)return;

	// 上に移動する
	position_.y += -kSpeed;

	// 画面外に出たら発射終了
	if (position_.y + kRadius < 0.0f) { isShot_ = false; }
}

/// @brief 描画処理
void Bullet::Draw()
{
	// 発射中のみ描画する
	if (!isShot_)return;

	Novice::DrawTriangle(static_cast<int>(position_.x), static_cast<int>(position_.y - kRadius),
		static_cast<int>(position_.x + kRadius), static_cast<int>(position_.y + kRadius),
		static_cast<int>(position_.x - kRadius), static_cast<int>(position_.y + kRadius), 0xFFFFFF77, kFillModeSolid);
}

/// @brief 発射
/// @param position 位置
void Bullet::Shot(const Vector2& position)
{
	// 発射中は処理しない
	if (isShot_)return;

	// 発射
	isShot_ = true;

	// 位置
	position_ = position;
}