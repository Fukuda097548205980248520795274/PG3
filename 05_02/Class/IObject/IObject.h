#pragma once
#include <cstdint>
#include "../../Math/Vector2Int/Vector2Int.h"

class IObject
{
public:

	/// @brief 仮想コンストラクタ
	virtual ~IObject() = default;

	/// @brief 描画処理
	virtual void Draw() = 0;


protected:

	/// @brief 移動可能な横幅
	static constexpr inline int32_t kMoveRangeWidth = 40;

	/// @brief 移動可能な縦幅
	static constexpr inline int32_t kMoveRangeHeight = 20;
};

