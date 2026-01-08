#pragma once
#include "../IScene.h"
#include <memory>

#include "../../IObject/Grid/Grid.h"
#include "../../IObject/Selecter/Selecter.h"

class StageScene : public IScene
{
public:

	/// @brief 初期化
	void Initialize() override;

	/// @brief 更新処理
	void Update() override;

	/// @brief 描画処理
	void Draw() override;


private:

	// グリッド
	std::unique_ptr<Grid> grid_ = nullptr;

	// セレクター
	std::unique_ptr<Selector> selector_ = nullptr;
};

