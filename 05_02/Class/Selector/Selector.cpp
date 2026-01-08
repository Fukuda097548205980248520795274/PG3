#include "Selector.h"
#include <Novice.h>

/// @brief 初期化
void Selector::Initialize()
{
	// ユニットを生成する
	while (units_.size() < 5)
	{
		int mapX = rand() % 40;
		int	mapY = rand() % 20;

		// 位置が被らないようにする
		bool isReset = false;
		for (int j = 0; j < units_.size(); ++j)
		{
			if (mapX == units_[j]->GetMapX() && mapY == units_[j]->GetMapY())
			{
				isReset = true;
				break;
			}
		}

		// リセット
		if (isReset)continue;

		std::unique_ptr<Unit> unit = std::make_unique<Unit>(mapX, mapY);
		unit->Initialize();

		units_.push_back(std::move(unit));
	}
}

/// @brief 更新処理
void Selector::Update()
{
	// ユニットの更新
	for (auto& unit : units_)unit->Update();
}

/// @brief 描画処理
void Selector::Draw()
{
	// ユニットの描画
	for (auto& unit : units_)unit->Draw();

	Novice::DrawBox(mapX_ * mapSize_, mapY_ * mapSize_, mapSize_, mapSize_, 0.0f, 0xFF0000FF, kFillModeWireFrame);
}

/// @brief 移動
/// @param x 
/// @param y 
void Selector::Move(int x, int y)
{
	// 移動
	mapX_ += x;
	mapY_ += y;
}

/// @brief ユニットを選ぶ
void Selector::SelectUnit()
{

}