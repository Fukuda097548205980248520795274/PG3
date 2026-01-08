#include "InputHandler.h"

#include <Novice.h>

#include "../ICommand/MoveUp/MoveUp.h"
#include "../ICommand/MoveLeft/MoveLeft.h"
#include "../ICommand/MoveDown/MoveDown.h"
#include "../ICommand/MoveRight/MoveRight.h"

void InputHandler::AssignMoveUpCommandTriggerKeyW()
{
	this->triggerKeyW_ = std::make_unique<MoveUp>();
}

void InputHandler::AssignMoveLeftCommandTriggerKeyA()
{
	this->triggerKeyA_ = std::make_unique<MoveLeft>();
}

void InputHandler::AssignMoveDownCommandTriggerKeyS()
{
	this->triggerKeyS_ = std::make_unique<MoveDown>();
}

void InputHandler::AssignMoveRightCommandTriggerKeyD()
{
	this->triggerKeyD_ = std::make_unique<MoveRight>();
}

ICommand* InputHandler::HandleInput(const char* key , const char* preKey)
{
	if (key[DIK_W] && !preKey[DIK_W])
	{
		return triggerKeyW_.get();
	}

	if (key[DIK_A] && !preKey[DIK_A])
	{
		return triggerKeyA_.get();
	}

	if (key[DIK_S] && !preKey[DIK_S])
	{
		return triggerKeyS_.get();
	}

	if (key[DIK_D] && !preKey[DIK_D])
	{
		return triggerKeyD_.get();
	}


	return nullptr;
}