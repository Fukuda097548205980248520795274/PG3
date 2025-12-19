#pragma once

// 2次元ベクトル
struct Vector2
{
	/// @brief コンストラクタ
	/// @param x 
	/// @param y 
	Vector2(float x, float y ) : x(x) , y(y){}

	float x;
	float y;

	/// @brief 加算
	/// @param vector 
	/// @return 
	Vector2 operator+=(const Vector2& vector)
	{
		this->x += vector.x;
		this->y += vector.y;
		return *this;
	}
};