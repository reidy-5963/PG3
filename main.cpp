#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <functional>

typedef void (*PFunc)(int);

std::function<void(int)> SetTimeout(int second, PFunc p) {
	Sleep(second * 1000);

	return [p](int answer) { p(answer); };
}

void DisplayDice(int answer) {
	int diceNum = 1 + rand() % 2;

	if (diceNum == 0) {
		printf_s("出目は丁\n");
	}
	else if (diceNum == 1) {
		printf_s("出目は半\n");
	}

	Sleep(1 * 1000);

	if (answer == diceNum) {
		printf_s("おめでとう! あなたは運があるね");
	}
	else if (answer != diceNum) {
		printf_s("残念！ あなたは運がない");
	}
}

int main() {
	srand((unsigned)time(nullptr));
	int isEvenOrOdd = 0;
	int isYesOrNo = 1;

	for (; isYesOrNo == 1;) {
		printf_s("丁(偶数)か半(奇数)か\n丁なら0を、半なら1を押してください\n");
		scanf_s("%d", &isEvenOrOdd);
		for (; (isEvenOrOdd < 0 || isEvenOrOdd > 1);) {
			printf_s("範囲外の回答です。もう一度お願いします。\n");
			scanf_s("%d", &isEvenOrOdd);

		}
		printf_s("ファイナルアンサー? はい : 0, いいえ : 1\n");
		scanf_s("%d", &isYesOrNo);
		for (; (isYesOrNo < 0 || isYesOrNo > 1);) {
			printf_s("範囲外の回答です。もう一度お願いします。\n");
			scanf_s("%d", &isYesOrNo);

		}
	}
	PFunc p;
	p = DisplayDice;
	auto diceGame = setTimeout(3, p);

	diceGame(isEvenOrOdd);
	return 0;
}