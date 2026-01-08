#pragma once

class IStageSceneCommand
{
public:

	/// @brief 仮想デストラクタ
	virtual ~IStageSceneCommand() = default;

	/// @brief 実行
	/// @param selector セレクター
	/// @param unit ユニット
	virtual void Exec() = 0;
};

