#pragma once
#define NOMINMAX
#include <functional>
#include "../IObject.h"

class InputManager;

class Player : public IObject
{
public:

	/// @brief コンストラクタ
	/// @param position 
	Player(Vector2 position) : IObject(position){}

	/// @brief 更新処理
	void Update() override;

	/// @brief 描画処理
	void Draw() override;

	/// @brief 入力の設定
	/// @param input 
	void InputOption(InputManager* input);

	/// @brief 発射関数の設定
	/// @param shotFunc 
	void SetShotFunc(std::function<void(const Vector2&)> shotFunc) { shotFunc_ = shotFunc; }


private:

	/// @brief 上に進む
	void MoveUp();

	/// @brief 左に進む
	void MoveLeft();

	/// @brief 下に進む
	void MoveDown();

	/// @brief 右に進む
	void MoveRight();


	// 速度ベクトル
	Vector2 velocity_ = Vector2(0.0f, 0.0f);

	// 移動速度
	const float kMoveSpeed = 4.0f;

	// 半径
	const float kRadius = 16.0f;


private:

	/// @brief 発射
	void Shot();
	
	// 発射関数
	std::function<void(const Vector2&)> shotFunc_ = nullptr;
};

