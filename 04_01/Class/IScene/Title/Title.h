#pragma once
#include "../IScene.h"

class Title : public IScene
{
public:

	/// @brief 初期化
	void Initialize() override;

	/// @brief 更新処理
	void Update() override;

	/// @brief 描画処理
	void Draw() override;


private:

	/// @brief ステージシーンに遷移する
	void TransitionGameStage();
};

