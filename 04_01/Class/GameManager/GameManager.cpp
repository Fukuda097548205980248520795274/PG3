#include "GameManager.h"
#include <Novice.h>

#include "../IScene/Title/Title.h"
#include "../IScene/Stage/Stage.h"
#include "../IScene/Clear/Clear.h"

GameManager::GameManager()
{
	// シーンの生成と初期化
	sceneArr_[static_cast<size_t>(SCENE::TITLE)] = std::make_unique<Title>();
	sceneArr_[static_cast<size_t>(SCENE::STAGE)] = std::make_unique<Stage>();
	sceneArr_[static_cast<size_t>(SCENE::CLEAR)] = std::make_unique<Clear>();

	// 初期シーンの設定
	currentScene_ = SCENE::TITLE;
	prevScene_ = SCENE::TITLE;

	// シーンの初期化
	sceneArr_[static_cast<size_t>(currentScene_)]->Initialize();
}

/// @brief 実行
/// @return 
int GameManager::Run()
{
	const char kWindowTitle[] = "LE2A_12_フクダ_ソウワ_PG3_ステートパターン";

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) 
	{
		// フレームの開始
		Novice::BeginFrame();

		// シーンのチェック
		prevScene_ = currentScene_;
		currentScene_ = sceneArr_[static_cast<size_t>(currentScene_)]->GetSceneNo();

		// シーンの切り替わりで初期化する
		if (currentScene_ != prevScene_)
		{
			sceneArr_[static_cast<size_t>(currentScene_)]->Initialize();
		}

		// 更新処理
		sceneArr_[static_cast<size_t>(currentScene_)]->Update();

		// 描画処理
		sceneArr_[static_cast<size_t>(currentScene_)]->Draw();

		// フレームの終了
		Novice::EndFrame();
	}


	// ライブラリの終了
	Novice::Finalize();
	return 0;
}