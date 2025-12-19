#include "InputManager.h"
#include <Novice.h>

/// @brief 入力処理の更新
void InputManager::Update()
{
	// キー入力を受け取る
	memcpy(preKeys_, keys_, 256);
	Novice::GetHitKeyStateAll(keys_);
}

/// @brief キーとその処理を登録する
/// @param key 
/// @param action 
void InputManager::RegistKeyEvent(BYTE key, KeyAction action)
{
	keyEvents_[key] = action;
}

/// @brief 入力判定
void InputManager::InputCheck()
{
	for (auto& [key, event] : keyEvents_)
	{
		// プレス
		if (event.press && keys_[key])event.press();

		// トリガー
		if (event.trigger && keys_[key] && !preKeys_[key])event.trigger();

		// リリース
		if (event.release && !keys_[key] && preKeys_[key])event.release();
	}
}