#pragma once
#include "../../Math/Vector2/Vector2.h"

class IObject
{
public:

	/// @brief コンストラクタ
	/// @param position 位置
	IObject(Vector2 position) : position_(position){}

	/// @brief 仮想デストラクタ
	virtual ~IObject() = default;

	/// @brief 更新処理
	virtual void Update() = 0;

	/// @brief 描画処理
	virtual void Draw() = 0;

	/// @brief 位置を取得する
	/// @return 
	Vector2 GetPosition()const { return position_; }


protected:


	// 位置
	Vector2 position_ = Vector2(0.0f, 0.0f);
};

