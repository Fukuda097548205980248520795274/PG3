#pragma once
#include "../IScene.h"
#include <memory>

#include "../../Selector/Selector.h"
#include "../../StageSceneInputHandler/StageSceneInputHandler.h"

class StageScene : public IScene
{
public:

	/// @brief 初期化
	void Initialize() override;

	/// @brief 更新処理
	void Update(const char* keys, const char* preKeys) override;

	/// @brief 描画処理
	void Draw() override;


private:

	// セレクター
	std::unique_ptr<Selector> selector_ = nullptr;

	// 入力ハンドラ
	std::unique_ptr<StageSceneInputHandler> inputHandler_ = nullptr;
};

