#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <functional>


enum class Dice {
	Even,	// 偶数
	Odd		// 奇数
};

enum class Answer {
	Yes,	// はい
	No		// いいえ
};

void DispResult(int* s) {
	printf_s("%d秒まって実行されたよ\n", *s);
}

typedef void (*PFunc)(int);
void setTimeout(PFunc p, int second, int answer) {
	Sleep(second * 1000);

	p(answer);
}

int RundomDice() {
	return 1 + rand() % 6;
}

void DiceGame(int answer) {
	int check = 0;
	int diceNum = RundomDice();

	// 出目が偶数なら0 奇数なら1
	check = diceNum % 2;

	printf_s("サイコロの出目 : %d\n", diceNum);
	Sleep(1 * 1000);

	if (check == int(Dice::Even)) {
		printf_s("出目は丁\n");
	}
	else if (check == int(Dice::Odd)) {
		printf_s("出目は半\n");
	}

	Sleep(1 * 1000);

	if (answer == check) {
		printf_s("おめでとう! あなたは運があるね");
	}
	else if (answer != check) {
		printf_s("残念！ あなたは運がない");
	}
}

int main() {
	srand((unsigned)time(nullptr));
	int isEvenOrOdd = 0;
	int isYesOrNo = int(Answer::No);
	while (isYesOrNo == int(Answer::Yes)) {
		printf_s("丁(偶数)か半(奇数)か\n丁なら0を、半なら1を押してください\n");
		scanf_s("%d", &isEvenOrOdd);
		while (isEvenOrOdd < int(Dice::Even) || isEvenOrOdd > int(Dice::Odd)) {
			printf_s("範囲外の回答です。もう一度お願いします。\n");
			scanf_s("%d", &isEvenOrOdd);

		}
		printf_s("ファイナルアンサー? はい : 0, いいえ : 1\n");
		scanf_s("%d", &isYesOrNo);
		for (; (isYesOrNo < int(Answer::Yes) || isYesOrNo > int(Answer::No));) {
			printf_s("範囲外の回答です。もう一度お願いします。\n");
			scanf_s("%d", &isYesOrNo);

		}
	}

	std::function<void(int)> allFunction = [](int i){};

	PFunc p;
	p = DiceGame;
	setTimeout(p, 3, isEvenOrOdd);

	return 0;
}