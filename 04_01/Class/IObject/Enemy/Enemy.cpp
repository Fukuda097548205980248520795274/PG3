#include "Enemy.h"

#include <Novice.h>
#include "../Bullet/Bullet.h"

/// @brief コンストラクタ
	/// @param position 
Enemy::Enemy(Vector2 position)
	: IObject(position) 
{
	ghExplosion_ = Novice::LoadTexture("./Resources/explode.png");
}

/// @brief 更新処理
void Enemy::Update()
{
	if (!isExplosion_)
	{
		// 位置を移動する
		position_ += velocity_;

		// 左右の両端で反転する
		if (position_.x + kRadius >= 1280.0f || position_.x - kRadius <= 0.0f) { velocity_.x *= -1.0f; }
	}
	else
	{
		// 爆発タイマーを進める
		explosionTimer_ -= 1.0f / 60.0f;

		// タイマーが越えたら終了する
		if (explosionTimer_ <= 0.0f)
		{
			isFinished_ = true;
		}
	}
}

/// @brief 描画処理
void Enemy::Draw()
{
	if (!isExplosion_)
	{
		// 自機
		Novice::DrawEllipse(static_cast<int>(position_.x), static_cast<int>(position_.y),
			static_cast<int>(kRadius), static_cast<int>(kRadius), 0.0f, 0xFFFFFFFF, kFillModeSolid);
	}
	else
	{
		if (explosionTimer_ < 1.0f)return;

		// 爆発
		Novice::DrawSprite(static_cast<int>(position_.x - kRadius), static_cast<int>(position_.y - kRadius),
			ghExplosion_, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
	}
}

/// @brief 衝突応答処理
/// @param bullet 
void Enemy::OnCollision()
{
	isExplosion_ = true;
}