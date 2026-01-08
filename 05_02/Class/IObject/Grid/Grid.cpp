#include "Grid.h"
#include <Novice.h>

/// @brief 描画処理
void Grid::Draw()
{
	for (int i = 0; i <= kMoveRangeWidth; ++i)
	{
		Novice::DrawLine(i * squareSize_, 0, i * squareSize_, 720, 0xFFFFFFFF);
	}

	for (int i = 0; i <= kMoveRangeHeight; ++i)
	{
		Novice::DrawLine(0, i * squareSize_, 1280, i * squareSize_, 0xFFFFFFFF);
	}
}