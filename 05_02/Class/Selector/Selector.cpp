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

	if (selectedUnit_)
	{
		// ユニットを選んでいるとき
		Novice::DrawBox(mapX_ * mapSize_ + 4, mapY_ * mapSize_ + 4, 24, 24, 0.0f, 0xFFAAAAFF, kFillModeSolid);
	}
	else
	{
		// ユニットを選んでいないとき
		Novice::DrawBox(mapX_ * mapSize_, mapY_ * mapSize_, mapSize_, mapSize_, 0.0f, 0xFF0000FF, kFillModeWireFrame);
	}
}

/// @brief 移動
/// @param x 
/// @param y 
void Selector::Move(int x, int y)
{
	// 範囲外に出ないようにする
	if (mapX_ + x < 0 || mapX_ + x >= 40)return;
	if (mapY_ + y < 0 || mapY_ + y >= 20)return;

	// ユニットを選んでいるとき
	if (selectedUnit_)
	{
		for (auto& unit : units_)
		{
			// 自分自身は無視
			if (unit.get() == selectedUnit_)
				continue;

			// 移動先にユニットがいるときは移動しない
			if (unit->GetMapX() == mapX_ + x && unit->GetMapY() == mapY_ + y)return;
		}

		// undoの回数をカウントする
		std::pair<int, int> undo = { x, y };
		undoList_.push_back(undo);
		undoCount_++;

		selectedUnit_->Move(x, y);
	}

	// 移動
	mapX_ += x;
	mapY_ += y;
}

/// @brief ユニットを選択or解除
void Selector::SelectOrCancellationUnit()
{
	// ユニットがないときは、選ぶ
	if (selectedUnit_ == nullptr)
	{
		// セレクターと同じ場所のユニットを探す
		for (auto& unit : units_)
		{
			if (mapX_ == unit->GetMapX() && mapY_ == unit->GetMapY())
			{
				selectedUnit_ = unit.get();
				break;
			}
		}
	}
	else
	{
		// ユニットがあるときは解除選択
		selectedUnit_ = nullptr;

		// undoリストをクリアする
		undoList_.clear();
		undoCount_ = 0;
	}
}

/// @brief 巻き戻す
void Selector::Undo()
{
	// 選んでいないとき undoがカウントされていないとき
	if (!selectedUnit_)return;
	if (undoCount_ <= 0)return;

	// 最新の操作を取得する
	std::pair<int, int> undo = undoList_.back();

	// 移動を巻き戻す
	UndoMove(-undo.first, -undo.second);

	// ポップする
	undoList_.pop_back();
	undoCount_--;
}

/// @brief undo用移動関数
/// @param x 
/// @param y 
void Selector::UndoMove(int x, int y)
{
	// 選んでいるユニットを動かす
	if (selectedUnit_)
	{
		selectedUnit_->Move(x, y);
	}

	// 移動
	mapX_ += x;
	mapY_ += y;
}