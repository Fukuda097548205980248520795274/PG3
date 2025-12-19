#include "Title.h"

/// @brief 初期化
void Title::Initialize()
{
	// キーと処理
	using KeyAction = InputManager::KeyAction;

	// スペースキーでステージシーンに遷移
	inputManager_->RegistKeyEvent(DIK_SPACE, KeyAction{ {},[&]() {TransitionGameStage(); } });
}

/// @brief 更新処理
void Title::Update()
{
	// 入力マネージャの更新
	inputManager_->Update();


	// 入力の判定
	inputManager_->InputCheck();
}

/// @brief 描画処理
void Title::Draw()
{
	Novice::ScreenPrintf(0, 0, "Title_Scene");
}


/// @brief ステージシーンに遷移する
void Title::TransitionGameStage()
{
	sceneNo = SCENE::STAGE;
}