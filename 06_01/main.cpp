#include <iostream>
#include <Windows.h>
#include <thread>
#include <functional>

int main()
{
	SetConsoleOutputCP(65001);

	int num = 1;

	std::function<void()> Printf1 = [&]() {std::cout << "thread1" << std::endl; num++; };
	std::function<void()> Printf2 = [&]() {while (num != 2) {}std::cout << "thread2" << std::endl; num++; };
	std::function<void()> Printf3 = [&]() {while (num != 3) {}std::cout << "thread3" << std::endl; };

	std::thread th1(Printf1);
	std::thread th2(Printf2);
	std::thread th3(Printf3);

	th1.join();
	th2.join();
	th3.join();

	return 0;
}