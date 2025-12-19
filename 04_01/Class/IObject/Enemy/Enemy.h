#pragma once
#include "../IObject.h"

class Enemy : public IObject
{
public:

	/// @brief コンストラクタ
	/// @param position 
	Enemy(Vector2 position) : IObject(position) {}

	/// @brief 更新処理
	void Update() override;

	/// @brief 描画処理
	void Draw() override;


private:

	// 速度ベクトル
	Vector2 velocity_ = Vector2(2.0f, 0.0f);

	// 半径
	const float kRadius = 16.0f;
};

