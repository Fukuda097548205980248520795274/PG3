#include "Bg.h"
#include <Novice.h>
#include <cmath>

/// @brief コンストラクタ
/// @param position 
Bg::Bg(const char* filePath) : IObject(Vector2(0.0f, 0.0f))
{
	// テクスチャを読み込む
	ghBg_ = Novice::LoadTexture(filePath);
}


/// @brief 更新処理
void Bg::Update()
{
	// 移動させる
	position_.y += kSpeed;

	// 画面外に出たら初期値に戻す
	position_.y = std::fmod(position_.y, 720.0f);
}

/// @brief 描画処理
void Bg::Draw()
{
	// 背景
	Novice::DrawSprite(static_cast<int>(position_.x), static_cast<int>(position_.y),
		ghBg_, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);

	// 背景
	Novice::DrawSprite(static_cast<int>(position_.x), static_cast<int>(position_.y - 720.0f),
		ghBg_, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
}