#include <iostream>
#include <Windows.h>
#include <list>

int main()
{
	// unicode BOM無し
	SetConsoleOutputCP(65001);


	/*-------------------
	    1970年の山手線
	-------------------*/
	
	std::list<const char*> yamanoteLineList;
	yamanoteLineList.push_back("Tokyo");
	yamanoteLineList.push_back("Kanda");
	yamanoteLineList.push_back("Akihabara");
	yamanoteLineList.push_back("Okachimachi");
	yamanoteLineList.push_back("Ueno");
	yamanoteLineList.push_back("Uguisudani");
	yamanoteLineList.push_back("Nippori");
	yamanoteLineList.push_back("Tabata");
	yamanoteLineList.push_back("Komagome");
	yamanoteLineList.push_back("Sugamo");
	yamanoteLineList.push_back("Otsuka");
	yamanoteLineList.push_back("Ikebukuro");
	yamanoteLineList.push_back("Mejiro");
	yamanoteLineList.push_back("Takadanobaba");
	yamanoteLineList.push_back("Shin-Okubo");
	yamanoteLineList.push_back("Shinjuku");
	yamanoteLineList.push_back("Yoyogi");
	yamanoteLineList.push_back("Harajuku");
	yamanoteLineList.push_back("Shibuya");
	yamanoteLineList.push_back("Ebisu");
	yamanoteLineList.push_back("Meguro");
	yamanoteLineList.push_back("Gotanda");
	yamanoteLineList.push_back("Osaki");
	yamanoteLineList.push_back("Shinagawa");
	yamanoteLineList.push_back("Tamachi");
	yamanoteLineList.push_back("Hamamatsucho");
	yamanoteLineList.push_back("Shimbashi");
	yamanoteLineList.push_back("Yurakucho");


	// 出力する
	printf("YamanoteLine : 1970 \n");
	for (std::list<const char*>::iterator itr = yamanoteLineList.begin(); itr != yamanoteLineList.end(); ++itr)
	{
		printf("%s \n", *itr);
	}
	printf("\n\n");


	/*-------------------
	    2019年の山手線
	-------------------*/

	// 西日暮里を差し込む
	for (std::list<const char*>::iterator itr = yamanoteLineList.begin(); itr != yamanoteLineList.end(); ++itr)
	{
		if (*itr == "Tabata")
		{
			itr = yamanoteLineList.insert(itr, "Nishi-Nippori");
			++itr;
			break;
		}
	}

	// 出力する
	printf("YamanoteLine : 2019 \n");
	for (std::list<const char*>::iterator itr = yamanoteLineList.begin(); itr != yamanoteLineList.end(); ++itr)
	{
		printf("%s \n", *itr);
	}
	printf("\n\n");


	/*-----------------
	    2022の山手線
	-----------------*/

	// 高輪ゲートウェイを差し込む
	for (std::list<const char*>::iterator itr = yamanoteLineList.begin(); itr != yamanoteLineList.end(); ++itr)
	{
		if (*itr == "Tamachi")
		{
			itr = yamanoteLineList.insert(itr, "Takanawa-Gateway");
			++itr;
			break;
		}
	}

	// 出力する
	printf("YamanoteLine : 2022 \n");
	for (std::list<const char*>::iterator itr = yamanoteLineList.begin(); itr != yamanoteLineList.end(); ++itr)
	{
		printf("%s \n", *itr);
	}
	printf("\n");


	return 0;
}