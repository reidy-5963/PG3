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
	void Draw();

	void NearState();
	void ShotState();
	void LeaveState();

private:
	State state_ = State::NEAR;
	static void (Enemy::* stateFuncTable[])();


};
void (Enemy::* stateFuncTable[])() = {
	&Enemy::NearState,
	&Enemy::ShotState,
	&Enemy::LeaveState
};

void Enemy::Initialize() {
}

void Enemy::Update() {
	(this->*stateFuncTable[static_cast<size_t>(state_)]());
}

void Enemy::Draw() {
}

void Enemy::NearState() {
	printf_s("近接");

}
void Enemy::ShotState() {

}
void Enemy::LeaveState() {

}


int main() {
	
	return 0;
}