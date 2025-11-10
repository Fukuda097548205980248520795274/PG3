#include <iostream>
#include <Windows.h>

template<typename T, typename T1, typename T2>
class Comparison
{
public:

	// コンストラクタ
	Comparison(T1 num1, T2 num2) : num1_(num1) , num2_(num2){}

	// 最小値を返却する
	T Min() { return num1_ < num2_ ? static_cast<T>(num1_) : static_cast<T>(num2_); }


private:

	T1 num1_;
	T2 num2_;
};

int main()
{
	SetConsoleOutputCP(65001);

	// int = int : int
	Comparison<int,int,int>* comparison1 = new Comparison<int,int,int>(10,15);
	printf("%d \n", comparison1->Min());

	// float = float : float
	Comparison<float, float, float>* comparison2 = new Comparison<float, float, float>(13.2f, 6.8f);
	printf("%f \n", comparison2->Min());

	// double = double : double
	Comparison<double, double, double>* comparison3 = new Comparison<double, double, double>(11.4f, 11.8f);
	printf("%lf \n", comparison3->Min());

	// float = int : float
	Comparison<float, int, float>* comparison4 = new Comparison<float, int, float>(10, 9.9);
	printf("%f \n", comparison4->Min());

	// double = int : double
	Comparison<double, int, double>* comparison5 = new Comparison<double, int, double>(8, 11.4);
	printf("%lf \n", comparison5->Min());

	// double = float : double
	Comparison<double, float, double>* comparison6 = new Comparison<double, float, double>(14.2, 13.1);
	printf("%lf \n", comparison6->Min());

	return 0;
}