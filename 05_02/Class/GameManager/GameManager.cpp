#include "GameManager.h"
#include <Novice.h>

#include "../IScene/StageScene/StageScene.h"

/// @brief コンストラクタ
GameManager::GameManager()
{
	// ステージシーンの生成と初期化
	scene_ = std::make_unique<StageScene>();
	scene_->Initialize();
}

/// @brief 実行
/// @return 
int GameManager::Run()
{
	const char kWindowTitle[] = "LE2A_12_フクダ_ソウワ_PG3_コマンドパターン";

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		// シーンの更新処理
		scene_->Update();

		// シーンの描画処理
		scene_->Draw();

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}