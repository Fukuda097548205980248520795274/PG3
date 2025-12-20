#pragma once
#include "../../Math/Vector2/Vector2.h"

class IObject
{
public:

	/// @brief 仮想デストラクタ
	virtual ~IObject() = default;

	/// @brief コンストラクタ
	/// @param position 
	IObject(const Vector2& position) : position_(position){}

	/// @brief 更新処理
	virtual void Update() = 0;

	/// @brief 描画処理
	virtual void Draw() = 0;


protected:


	// 位置
	Vector2 position_ = Vector2(0.0f, 0.0f);
};

