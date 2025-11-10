#include <iostream>
#include <Windows.h>

// 敵の状態
enum class EnemyState
{
	Approach,
	Shooting,
	Withdrawal,
	kMaxEnemyState
};

// 敵
class Enemy
{
public:

	// コンストラクタ
	Enemy(EnemyState state)
	{
		// 状態関数のテーブルを初期化する
		stateTable[static_cast<size_t>(EnemyState::Approach)] = &Enemy::Approach;
		stateTable[static_cast<size_t>(EnemyState::Shooting)] = &Enemy::Shooting;
		stateTable[static_cast<size_t>(EnemyState::Withdrawal)] = &Enemy::Withdrawal;

		// 引数を受け取る
		state_ = state;
	}

	// 文字出力
	void Print()
	{
		(this->*stateTable[static_cast<size_t>(state_)])();
	}

	// 状態を遷移する
	void TransitionState(EnemyState state) { state_ = state; }


private:

	// 接近
	void Approach()
	{
		std::cout << "Approach" << std::endl;
	}

	// 射撃
	void Shooting()
	{
		std::cout << "Shooting" << std::endl;
	}

	// 離脱
	void Withdrawal()
	{
		std::cout << "Withdrawal" << std::endl;
	}


	// 状態関数のテーブル
	void(Enemy::* stateTable[static_cast<size_t>(EnemyState::kMaxEnemyState)])();

	// 敵の状態
	EnemyState state_;
};


int main()
{
	SetConsoleOutputCP(65001);

	// 敵を生成する（接近から）
	Enemy* enemy = new Enemy(EnemyState::Approach);

	// 敵の状態出力
	enemy->Print();

	// 射撃に遷移し状態出力
	enemy->TransitionState(EnemyState::Shooting);
	enemy->Print();

	// 離脱に遷移し状態出力
	enemy->TransitionState(EnemyState::Withdrawal);
	enemy->Print();

	// 敵を削除する
	delete enemy;

	return 0;
}