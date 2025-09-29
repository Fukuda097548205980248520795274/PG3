#include <iostream>
#include <Windows.h>

int main()
{
	// unicode BOM無し
	SetConsoleOutputCP(65001);
	
	// 文字列出力
	char str[] = "コンニチハ !!";
	printf("%s", str);

	return 0;
}