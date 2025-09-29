#include <iostream>
#include <Windows.h>

int main()
{
	// unicode BOM無し
	SetConsoleOutputCP(65001);

	return 0;
}