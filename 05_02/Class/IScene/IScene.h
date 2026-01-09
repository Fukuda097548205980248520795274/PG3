#pragma once

class IScene
{
public:

	/// @brief 仮想デストラクタ
	virtual ~IScene() = default;

	/// @brief 初期化
	virtual void Initialize() = 0;

	/// @brief 更新処理
	virtual void Update(const char* keys, const char* preKeys) = 0;

	/// @brief 描画処理
	virtual void Draw() = 0;


protected:


};

