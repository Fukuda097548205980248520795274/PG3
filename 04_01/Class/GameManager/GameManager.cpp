#include "GameManager.h"
#include <Novice.h>

#include "../IScene/TitleScene/TitleScene.h"
#include "../IScene/StageScene/StageScene.h"
#include "../IScene/ClearScene/ClearScene.h"

GameManager::GameManager()
{
	// タイトルシーンの生成と初期化
	scene_ = std::make_unique<TitleScene>();
	scene_->Initialize();

	// 初期シーンの設定
	currentScene_ = SCENE::TITLE;
	prevScene_ = SCENE::TITLE;
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
		currentScene_ = scene_->GetSceneNo();

		// シーンの切り替わりで生成、初期化する
		if (currentScene_ != prevScene_)
		{
			switch (currentScene_)
			{
			case SCENE::TITLE:
			default:
				// タイトルシーン
				scene_ = std::make_unique<TitleScene>();
				break;

			case SCENE::STAGE:
				// ステージシーン
				scene_ = std::make_unique<StageScene>();
				break;

			case SCENE::CLEAR:
				// クリアシーン
				scene_ = std::make_unique<ClearScene>();
				break;
			}

			// シーンの初期化
			scene_->Initialize();
		}

		// 更新処理
		scene_->Update();

		// 描画処理
		scene_->Draw();

		// フレームの終了
		Novice::EndFrame();
	}


	// ライブラリの終了
	Novice::Finalize();
	return 0;
}