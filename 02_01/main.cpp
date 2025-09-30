#include <iostream>
#include <Windows.h>

template <typename T>

// 最小値を返却する
T Min(T value1, T value2)
{
	// 小さい値を返却する
	if (value1 < value2)
	{
		return value1;
	}
	else
	{
		return value2;
	}
}

int main()
{
	SetConsoleOutputCP(65001);

	// 整数型
	int numInt0 = 3;
	int numInt1 = 6;

	// 単精度浮動小数点
	float numFloat0 = 24.1f;
	float numFloat1 = 12.8f;

	// 倍精度浮動小数点
	double numDouble0 = 128.6;
	double numDouble1 = 97.3;

	// 関数テンプレートを用いて、最小値を求める
	printf("Min<int>(%d, %d) = %d \n", numInt0, numInt1, Min<int>(numInt0, numInt1));
	printf("Min<float>(%f, %f) = %f \n", numFloat0, numFloat1, Min<float>(numFloat0, numFloat1));
	printf("Min<double>(%lf, %lf) = %lf \n", numDouble0, numDouble1, Min<double>(numDouble0, numDouble1));

	return 0;
}