#pragma once

class Selector;

class Unit
{
public:

	/// @brief コンストラクタ
	/// @param x 
	/// @param y 
	Unit(int x, int y) : mapX_(x) , mapY_(y){}

	/// @brief 初期化
	void Initialize();

	/// @brief 更新処理
	void Update();

	/// @brief 描画処理
	void Draw();


	/// @brief mapXを取得する
	/// @return 
	int GetMapX()const { return mapX_; }

	/// @brief mapYを取得する
	/// @return 
	int GetMapY()const { return mapY_; }


	/// @brief 移動
	/// @param x 
	/// @param y 
	void Move(int x, int y);

	/// @brief 移動をやめる
	void MoveEnd();

private:

	int mapX_ = 0;
	int mapY_ = 0;

	/// @brief マップサイズ
	int mapSize_ = 24;


private:

	/// @brief 選ばれたかどうか
	bool isSelected_ = false;
};

