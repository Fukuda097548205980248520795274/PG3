#pragma once
#include <cmath>

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

	/// @brief 長さ
	/// @return 
	float Length()
	{
		float length = std::sqrt(std::powf(this->x, 2.0f) + std::powf(this->y, 2.0f));
		return length;
	}
};

namespace
{
	/// @brief 減算
	/// @param v1 
	/// @param v2 
	/// @return 
	Vector2 operator-(const Vector2& v1, const Vector2& v2)
	{
		Vector2 vector = Vector2(0.0f, 0.0f);
		vector.x = v1.x - v2.x;
		vector.y = v1.y - v2.y;
		return vector;
	}
}