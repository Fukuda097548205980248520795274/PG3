#include <iostream>
#include <Windows.h>
#include <thread>
#include <functional>

int main()
{
	SetConsoleOutputCP(65001);

	std::function<void()> Printf1 = [&]() {std::cout << "thread1" << std::endl; };
	std::function<void()> Printf2 = [&]() {std::cout << "thread2" << std::endl; };
	std::function<void()> Printf3 = [&]() {std::cout << "thread3" << std::endl; };

	std::thread th1(Printf1);
	th1.join();

	std::thread th2(Printf2);
	th2.join();

	std::thread th3(Printf3);
	th3.join();

	return 0;
}