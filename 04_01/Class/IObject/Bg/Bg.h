#pragma once
#include "../IObject.h"

class Bg : public IObject
{
public:

	/// @brief コンストラクタ
	/// @param position 
	Bg(const char* filePath);

	/// @brief 更新処理
	void Update() override;

	/// @brief 描画処理
	void Draw() override;


private:

	// 背景テクスチャ
	int ghBg_ = 0;


	// 移動速度
	const float kSpeed = 2.0f;
};

