#pragma once

class IScene
{
public:

	/// @brief 仮想デストラクタ
	virtual ~IScene() = default;

	/// @brief 初期化
	virtual void Initialize() = 0;

	/// @brief 更新処理
	virtual void Update(const char* key, const char* preKey) = 0;

	/// @brief 描画処理
	virtual void Draw() = 0;
};

