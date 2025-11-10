#include <iostream>
#include <Windows.h>
#include <numbers>

// 図形クラス
class IShape
{
public:

	// 面積を求める
	virtual void Size() = 0;

	// 描画する
	virtual void Draw() = 0;

protected:

	// 面積
	float area_ = 0.0f;
};

// 円クラス
class Circle : public IShape
{
public:

	// コンストラクタ
	Circle(float radius) : radius_(radius)
	{
		// マイナスにならないようにする
		if (radius_ < 0.0f) { radius_ = 0.0f; }
	}

	// 面積を求める
	void Size() override
	{
		area_ = radius_ * radius_ * std::numbers::pi_v<float>;
	}

	// 描画する
	void Draw() override
	{
		std::cout << "円の面積 : " << area_ << std::endl;
	}

private:

	// 半径
	float radius_ = 0.0f;
};

// 矩形クラス
class Rect : public IShape
{
public:

	// コンストラクタ
	Rect(float width, float height) : width_(width), height_(height)
	{
		// マイナスにならないようにする
		if (width_ < 0.0f) { width_ = 0.0f; }
		if (height_ < 0.0f) { height_ = 0.0f; }
	}

	// 面積を求める
	void Size() override
	{
		area_ = width_ * height_;
	}

	// 描画する
	void Draw() override
	{
		std::cout << "矩形の面積 : " << area_ << std::endl;
	}

private:

	// 縦
	float height_ = 0.0f;

	// 横
	float width_ = 0.0f;
};


int main()
{
	SetConsoleOutputCP(65001);


	// 円
	IShape* circle = new Circle(8.0f);
	circle->Size();
	circle->Draw();

	// 矩形
	IShape* rect = new Rect(6.0f, 9.0f);
	rect->Size();
	rect->Draw();


	// 図形を削除
	delete circle;
	circle = nullptr;

	delete rect;
	rect = nullptr;


	return 0;
}