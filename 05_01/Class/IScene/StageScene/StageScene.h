#pragma once
#include "../IScene.h"

#include <memory>
#include "../../IObject/Player/Player.h"
#include "../../InputHandler/InputHandler.h"

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


	// プレイヤー
	std::unique_ptr<Player> player_ = nullptr;

	// 入力ハンドル
	std::unique_ptr<InputHandler> inputHandler_ = nullptr;
};

