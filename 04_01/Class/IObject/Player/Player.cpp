#include "Player.h"

#include <cassert>
#include <algorithm>

#include "../../InputManager/InputManager.h"

/// @brief 更新処理
void Player::Update()
{
	// 位置を移動させる
	position_ += velocity_;

	// 画面外に出ないようにする
	position_.x = std::max(position_.x, kRadius);
	position_.x = std::min(position_.x, 1280.0f - kRadius);
	position_.y = std::max(position_.y, kRadius);
	position_.y = std::min(position_.y, 720.0f - kRadius);

	// 速度ベクトルを初期化する
	velocity_ = Vector2(0.0f, 0.0f);
}

/// @brief 描画処理
void Player::Draw()
{
	// プレイヤーを描画する
	Novice::DrawBox(static_cast<int>(position_.x - kRadius), static_cast<int>(position_.y - kRadius),
		static_cast<int>(kRadius) * 2, static_cast<int>(kRadius) * 2, 0.0f, 0xFFFFFF77, kFillModeSolid);
}

/// @brief 入力の設定
/// @param input 
void Player::InputOption(InputManager* input)
{
	using KeyAction = InputManager::KeyAction;

	input->RegistKeyEvent(DIK_W, KeyAction{ [&]() {MoveUp(); } });
	input->RegistKeyEvent(DIK_A, KeyAction{ [&]() {MoveLeft(); } });
	input->RegistKeyEvent(DIK_S, KeyAction{ [&]() {MoveDown(); } });
	input->RegistKeyEvent(DIK_D, KeyAction{ [&]() {MoveRight(); } });
	input->RegistKeyEvent(DIK_SPACE, KeyAction{ {}, [&]() {Shot(); } });
}



/// @brief 上に進む
void Player::MoveUp()
{
	velocity_.y += -kMoveSpeed;
}

/// @brief 左に進む
void Player::MoveLeft()
{
	velocity_.x += -kMoveSpeed;
}

/// @brief 下に進む
void Player::MoveDown()
{
	velocity_.y += kMoveSpeed;
}

/// @brief 右に進む
void Player::MoveRight()
{
	velocity_.x += kMoveSpeed;
}

/// @brief 発射
void Player::Shot()
{
	// 関数が設定されているときのみ
	if (shotFunc_)shotFunc_(position_);
}