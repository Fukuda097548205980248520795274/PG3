#include "TitleScene.h"

/// @brief 初期化
void TitleScene::Initialize()
{
	// キーと処理
	using KeyAction = InputManager::KeyAction;

	// スペースキーでステージシーンに遷移
	inputManager_->RegistKeyEvent(DIK_SPACE, KeyAction{ {},[&]() {TransitionStage(); } });
}

/// @brief 更新処理
void TitleScene::Update()
{
	// 入力マネージャの更新
	inputManager_->Update();


	// 入力の判定
	inputManager_->InputCheck();
}

/// @brief 描画処理
void TitleScene::Draw()
{
	Novice::ScreenPrintf(0, 0, "Title_Scene");
}


/// @brief ステージシーンに遷移する
void TitleScene::TransitionStage()
{
	sceneNo = SCENE::STAGE;
}