#pragma once
#include <memory>
#include <functional>
#include <array>
#include <mutex>

class GameManager
{
public:

	/// @brief 実行
	/// @return 
	int Run();


private:

	/// @brief マップ更新関数を取得
	/// @return 
	std::function<void()> MapUpdateThread();

	std::mutex mutex;

	/// @brief マップ
	std::array<std::array<int, 40>, 20> map_ = {0};
};

