#include "Player.h"
#include <Novice.h>

/// @brief 更新処理
void Player::Update()
{

}

/// @brief 描画処理
void Player::Draw()
{
	Novice::DrawBox(static_cast<int>(position_.x - kRadius), static_cast<int>(position_.y - kRadius),
		static_cast<int>(kRadius * 2.0f), static_cast<int>(kRadius * 2.0f), 0.0f, 0xFFFFFFFF, kFillModeSolid);
}

/// @brief 左に進む
void Player::MoveLeft()
{
	position_.x += -kMoveSpeed;
}

/// @brief 右に進む
void Player::MoveRight()
{
	position_.x += kMoveSpeed;
}