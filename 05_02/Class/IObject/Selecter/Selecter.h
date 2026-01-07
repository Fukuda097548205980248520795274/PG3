#pragma once
#include "../IObject.h"

class Selecter : public IObject
{
public:

	/// @brief 更新処理
	void Update() override;

	/// @brief 描画処理
	void Draw() override;
};

