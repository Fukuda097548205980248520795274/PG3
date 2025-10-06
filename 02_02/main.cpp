#include <iostream>
#include <Windows.h>

/// <summary>
/// 時給計算
/// </summary>
/// <param name="hourlyWage">時給</param>
/// <param name="hour">時</param>
/// <returns></returns>
int32_t HourlyWages(int32_t hourlyWage, int32_t hour)
{
	// 時間が無くなるまで計算する
	if (hour > 0)
	{
		return hourlyWage + HourlyWages(hourlyWage, hour - 1);
	}

	return 0;
}

/// <summary>
/// 再帰的な珍言計算
/// </summary>
/// <param name="startWages">最初の賃金</param>
/// <param name="hour">時</param>
/// <returns></returns>
int32_t RecursiveWages(int32_t startWage, int32_t hour)
{
	// 時間が無くなるまで計算する
	if (hour > 0)
	{
		return startWage + RecursiveWages(startWage * 2 - 50, hour - 1);
	}

	return 0;
}


int main()
{
	// 文字コード設定
	SetConsoleOutputCP(65001);

	// 時給
	int32_t hourlyWage = 1226;

	// 最初の賃金
	int32_t startWage = 100;

	// 時間
	int32_t hour = 8;


	// 5時間働いたとき
	printf("働いた時間 : %d , 合計賃金 : %d \n", hour, HourlyWages(hourlyWage, hour));
	printf("働いた時間 : %d , 合計賃金 : %d \n", hour, RecursiveWages(startWage, hour));

	return 0;
}