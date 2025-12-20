#pragma once
#include <memory>
#include "../InputManager/InputManager.h"

// シーン
enum class SCENE
{
	TITLE,
	STAGE,
	CLEAR
};

class IScene
{
public:

	/// @brief コンストラクタ
	IScene();

	/// @brief 仮想デストラクタ
	virtual ~IScene() = default;

	/// @brief 初期化
	virtual void Initialize() = 0;

	/// @brief 更新処理
	virtual void Update() = 0;

	/// @brief 描画処理
	virtual void Draw() = 0;

	/// @brief シーン番号を取得する
	/// @return 
	SCENE GetSceneNo()const { return sceneNo; }


protected:

	// シーン番号
	static SCENE sceneNo;

	// 入力マネージャ
	std::unique_ptr<InputManager> inputManager_ = nullptr;
};

