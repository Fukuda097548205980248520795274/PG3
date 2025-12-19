#pragma once
#include <Novice.h>
#include <unordered_map>
#include <functional>

class InputManager
{
public:

	struct KeyAction
	{
		std::function<void()> press = nullptr;
		std::function<void()> trigger = nullptr;
		std::function<void()> release = nullptr;
	};


public:

	/// @brief 更新処理
	void Update();

	/// @brief 入力判定
	void InputCheck();

	/// @brief キーとその処理を登録する
	/// @param key 
	/// @param action 
	void RegistKeyEvent(BYTE key, KeyAction action);


private:

	// キー
	char keys_[256] = { 0 };

	// 直前のキー
	char preKeys_[256] = { 0 };

	// キーと処理の紐づけ
	std::unordered_map<BYTE, KeyAction> keyEvents_;
};

