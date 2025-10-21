#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

/// <summary>
/// 遅延実行関数
/// </summary>
/// <param name="fn">呼び出したい関数のポインタ</param>
/// <param name="delayMs">待機時間</param>
/// <param name="roll">サイコロの出目</param>
/// <param name="userGuess">ユーザの入力</param>
void DelayReveal(void (*fn)(int, int), unsigned int delayMs, int roll, int userGuess)
{
	// 待機する
	Sleep(delayMs);

	// 関数ポインタ実行
	fn(roll, userGuess);
}

/// <summary>
/// 判定関数
/// </summary>
/// <param name="roll"></param>
/// <param name="userGuess"></param>
void ShowResult(int roll, int userGuess)
{
	printf("出目は %d でした \n", roll);

	// 奇数のとき
	if (roll % 2 == 1)
	{
		if (userGuess == 1)
		{
			printf("正解 \n");
		}
		else
		{
			printf("不正解 \n");
		}
	}

	// 偶数のとき
	if (roll % 2 == 0)
	{
		if (userGuess == 0)
		{
			printf("正解 \n");
		} else
		{
			printf("不正解 \n");
		}
	}
}


int main()
{
	// 文字コード設定
	SetConsoleOutputCP(65001);

	// 乱数のシード設定
	srand(static_cast<unsigned int>(time(NULL)));

	// 入力値
	int inputValue = 0;

	// サイコロの出目
	int roll = rand() % 6 + 1;

	
	printf("丁(偶数) と 半(奇数) を当てるゲーム　\n");
	printf("丁 => 0 , 半 => 1 : ");
	scanf_s("%d", &inputValue);

	DelayReveal(ShowResult, 3000, roll, inputValue);

	return 0;
}