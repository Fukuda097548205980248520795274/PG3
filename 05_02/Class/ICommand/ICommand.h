#pragma once

class Selector;

class ICommand
{
public:

	/// @brief 仮想デストラクタ
	virtual ~ICommand() = default;

	/// @brief 実行
	/// @param slector 
	virtual void Exec(Selector& slector) = 0;

};

