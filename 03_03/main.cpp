#include <iostream>
#include <Windows.h>
#include <list>

// 惑星
class Planet
{
public:

	// 神
	virtual void God() = 0;
};

// 水星
class Mercury : public Planet
{
public:

	// 神
	void God()override
	{
		std::cout << "水星（マーキュリー)  , ギリシャ神話 : 神々の使者である命令の神 ヘルメス" << std::endl;
	}
};

// 金星
class Venus : public Planet
{
public:

	// 神
	void God() override
	{
		std::cout << "金星（ヴィーナス)  , ギリシャ神話 : 美と愛の女神 アフロディテ" << std::endl;
	}
};

// 地球
class Earth : public Planet
{
public:

	// 神
	void God() override
	{
		std::cout << "地球（アース） , ギリシャ神話 : なし" << std::endl;
	}
};

// 火星
class Mars : public Planet
{
public:

	// 神
	void God() override
	{
		std::cout << "火星（マーズ） , ギリシャ神話 : 戦いの神 アーレス" << std::endl;
	}
};

// 木星
class Jupiter : public Planet
{
public:

	// 神
	void God() override
	{
		std::cout << "木星（ジュピター） , ギリシャ神話 : 全知全能の神 ゼウス" << std::endl;
	}
};

// 土星
class Satan : public Planet
{
public:

	// 神
	void God() override
	{
		std::cout << "土星（サターン） , ギリシャ神話 : 大地および農耕の神 クロノス" << std::endl;
	}
};

// 天王星
class Ouranus : public Planet
{
public:

	// 神
	void God() override
	{
		std::cout << "天王星（ウラノス） , ギリシャ神話 : 天空の神 ウラノス" << std::endl;
	}
};

// 海王星
class Neptune : public Planet
{
public:

	// 神
	void God() override
	{
		std::cout << "海王星（ネプチューン） , ギリシャ神話 : 海と地震を司る神 ポセイドン" << std::endl;
	}
};


int main()
{
	SetConsoleOutputCP(65001);

	// 惑星リスト
	std::list<Planet*> planets;
	planets.push_back(new Mercury());
	planets.push_back(new Venus());
	planets.push_back(new Earth());
	planets.push_back(new Mars());
	planets.push_back(new Jupiter());
	planets.push_back(new Satan());
	planets.push_back(new Neptune());

	// 神について文字出力する
	for (Planet* planet : planets)
	{
		planet->God();
	}

	// リストを削除する
	for (Planet* planet : planets)
	{
		delete planet;
	}
	planets.clear();


	return 0;
}