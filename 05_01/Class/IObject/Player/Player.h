#pragma once
#include "../IObject.h"

class Player : public IObject
{
public:

	/// @brief コンストラクタ
	/// @param position 
	Player(const Vector2& position) : IObject(position){}

	/// @brief 更新処理
	void Update() override;

	/// @brief 描画処理
	void Draw() override;


	/// @brief 左に進む
	void MoveLeft();

	/// @brief 右に進む
	void MoveRight();


private:

	// 半径
	const float kRadius = 16.0f;

	// 移動速度
	const float kMoveSpeed = 4.0f;
};

