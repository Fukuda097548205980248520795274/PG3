#include <Novice.h>
#include "Class/GameManager/GameManager.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
	std::unique_ptr<GameManager> gameManager = std::make_unique<GameManager>();
	return gameManager->Run();
}
