#include "ClearScene.h"

/// @brief 初期化
void ClearScene::Initialize()
{
	// キーと処理
	using KeyAction = InputManager::KeyAction;

	// スペースキーでステージシーンに遷移
	inputManager_->RegistKeyEvent(DIK_SPACE, KeyAction{ {},[&]() {TransitionTitle(); } });


	inputManager_->Update();
}

/// @brief 更新処理
void ClearScene::Update()
{
	// 入力マネージャの更新
	inputManager_->Update();


	// 入力の判定
	inputManager_->InputCheck();
}

/// @brief 描画処理
void ClearScene::Draw()
{
	Novice::ScreenPrintf(0, 0, "Clear_Scene");
}

/// @brief タイトルシーンに遷移する
void ClearScene::TransitionTitle()
{
	sceneNo = SCENE::TITLE;
}