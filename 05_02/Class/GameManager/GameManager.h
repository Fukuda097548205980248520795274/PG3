#pragma once
#include <Windows.h>
#include <memory>
#include "../IScene/IScene.h"

class GameManager
{
public:

	/// @brief コンストラクタ
	GameManager();

	/// @brief 実行
	/// @return 
	int Run();


private:

	// シーン
	std::unique_ptr<IScene> scene_ = nullptr;
};

