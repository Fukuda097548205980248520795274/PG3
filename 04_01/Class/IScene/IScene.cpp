#include "IScene.h"

// シーン番号
SCENE IScene::sceneNo = SCENE::TITLE;

/// @brief コンストラクタ
IScene::IScene()
{
	// 入力マネージャの生成
	inputManager_ = std::make_unique<InputManager>();
}