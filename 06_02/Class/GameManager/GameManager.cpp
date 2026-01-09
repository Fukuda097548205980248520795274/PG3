#include "GameManager.h"
#include <Novice.h>
#include <fstream>
#include <sstream>
#include <cassert>
#include <thread>

/// @brief 実行
/// @return 
int GameManager::Run()
{
	const char kWindowTitle[] = "LE2A_12_フクダ_ソウワ_PG3_thread";

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	std::thread th(MapUpdateThread());

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 40; ++j)
			{
				if (map_[i][j] == 1)
				{
					Novice::DrawBox(j * 32, i * 32, 32, 32, 0.0f, 0xFFFFFFFF, kFillModeSolid);
				}
			}
		}

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	th.join();

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

/// @brief マップ更新関数を取得
/// @return 
std::function<void()> GameManager::MapUpdateThread()
{
	return [&]()
		{
			std::lock_guard<std::mutex> lock(mutex);

			// ファイルを読み込む
			std::ifstream file;
			file.open("./Resources/map.csv");
			assert(file.is_open());

			// 文字列ストリーム
			std::stringstream mapChipCsv;

			// ファイルの内容を文字列ストリームにコピーする
			mapChipCsv << file.rdbuf();

			// ファイルを閉じる
			file.close();

			for (auto& mapLine : map_)
			{
				std::string line;
				getline(mapChipCsv, line);

				std::istringstream line_stream(line);

				for (auto& map : mapLine)
				{
					std::string word;
					getline(line_stream, word, ',');

					map = std::stoi(word);
				}
			}
		};
}