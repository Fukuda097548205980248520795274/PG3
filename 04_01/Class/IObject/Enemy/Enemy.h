#pragma once
#include "../IObject.h"

class Bullet;

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

	/// @brief 終了したかどうか
	/// @return 
	bool IsFinished()const { return isFinished_; }

	/// @brief 半径を取得する
	/// @return 
	float GetRadius()const { return kRadius; }

	/// @brief 衝突応答処理
	/// @param bullet 
	void OnCollision();


private:

	// 終了フラグ
	bool isFinished_ = false;


private:

	// 速度ベクトル
	Vector2 velocity_ = Vector2(2.0f, 0.0f);

	// 半径
	const float kRadius = 16.0f;
};

