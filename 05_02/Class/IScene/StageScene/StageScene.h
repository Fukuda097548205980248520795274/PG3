#pragma once
#include "../IScene.h"
#include <memory>

#include "../../InputHandler/InputHandler.h"
#include "../../IObject/Grid/Grid.h"
#include "../../IObject/Selecter/Selecter.h"

class StageScene : public IScene
{
public:

	/// @brief 初期化
	void Initialize() override;

	/// @brief 更新処理
	void Update(const char* key, const char* preKey) override;

	/// @brief 描画処理
	void Draw() override;


private:

	// 入力ハンドラ
	std::unique_ptr<InputHandler> inputHandler_ = nullptr;

	// グリッド
	std::unique_ptr<Grid> grid_ = nullptr;

	// セレクター
	std::unique_ptr<Selector> selector_ = nullptr;
};

