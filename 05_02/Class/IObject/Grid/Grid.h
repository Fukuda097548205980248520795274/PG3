#pragma once
#include "../IObject.h"

class Grid : public IObject
{
public:

	/// @brief 描画処理
	void Draw() override;


private:

	int squareSize_ = 32;
};

