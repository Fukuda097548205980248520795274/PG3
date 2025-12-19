#pragma once
#include "../IObject.h"

class Bullet : public IObject
{
public:

	/// @brief コンストラクタ
	Bullet() : IObject(Vector2(0.0f, 0.0f)){}

	/// @brief 更新処理
	void Update() override;

	/// @brief 描画処理
	void Draw() override;

	/// @brief 発射
	/// @param position 位置
	void Shot(const Vector2& position);


private:

	// 半径
	const float kRadius = 16.0f;

	// 発射速度
	const float kSpeed = 4.0f;


	// 発射しているかどうか
	bool isShot_ = false;
};

