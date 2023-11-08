#include <stdio.h>

class Enemy {
public:
	enum class State {
		NEAR,
		SHOT,
		LEAVE
	};
	void Initialize();
	void Update();

	void NearState();
	void ShotState();
	void LeaveState();

	bool IsAttack() { return isAttack_; }
private:
	State state_ = State::NEAR;

	static void (Enemy::* stateFuncTable[])();

	bool isAttack_ = false;
};

void (Enemy::* Enemy::stateFuncTable[])() = {
	&Enemy::NearState,
	&Enemy::ShotState,
	&Enemy::LeaveState
};

void Enemy::Initialize() {
	state_ = State::NEAR;
	isAttack_ = true;
}

void Enemy::Update() {

	(this->*stateFuncTable[static_cast<size_t>(state_)])();

}

void Enemy::NearState() {
	printf_s("近接\n敵の斧攻撃！\n\n");
	state_ = State::SHOT;
}
void Enemy::ShotState() {
	printf_s("射撃\n敵のビーム攻撃！\n\n");
	state_ = State::LEAVE;

}
void Enemy::LeaveState() {
	printf_s("離脱\n敵は離れた！\n\n");
	isAttack_ = false;
}


int main() {
	Enemy* enemy;
	enemy = new Enemy;
	enemy->Initialize();


	while (enemy->IsAttack()) {
		enemy->Update();
	}

	return 0;
}