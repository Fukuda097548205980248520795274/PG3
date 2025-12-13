#include <stdio.h>
#include <algorithm>
#include <Windows.h>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>
#include <sstream>

/// <summary>
/// 文字列を出力する
/// </summary>
/// <param name="studentID"></param>
void PrintfString(const std::string& studentID)
{
	printf("%s \n", studentID.c_str());
}

int main()
{
	// unicode BOM無し
	SetConsoleOutputCP(65001);

	// 学生番号
	std::vector<std::string> studentIDs;


	/*--------------------
		ファイル読み込み
	--------------------*/

	// ファイルを読み込む
	std::ifstream file;
	file.open("PG3_2025_01_02.txt");
	assert(file.is_open());

	// 文字列ストリームに変換する
	std::stringstream stream;
	stream << file.rdbuf();

	// ファイルを閉じる
	file.close();

	// 単語を入れる場所
	std::string word;

	// カンマ区切りで取得する
	while (std::getline(stream, word, ','))
	{
		studentIDs.push_back(word);
	}


	/*---------------------
		学籍番号順に並べる
	---------------------*/

	// 昇順に並べ替え
	sort(studentIDs.begin(), studentIDs.end());

	// 整列後を表示する
	printf("学籍番号 : 整列後\n");
	std::for_each(std::begin(studentIDs), std::end(studentIDs), PrintfString);


	return 0;
}