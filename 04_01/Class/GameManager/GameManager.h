#pragma once
#include <memory>
#include "../IScene/IScene.h"

class GameManager
{
public:

	/// @brief コンストラクタ
	GameManager();

	/// @brief デストラクタ
	~GameManager() = default;

	/// @brief 実行
	/// @return 
	int Run();


private:

	// シーン
	std::unique_ptr<IScene> scene_ = nullptr;

	// 現在のシーン
	SCENE currentScene_;

	// 前のシーン
	SCENE prevScene_;
};

