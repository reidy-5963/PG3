#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <functional>

void SetTimeOut(std::function<void()> pFunc, int second) {
	Sleep(second * 1000);

	pFunc();
}

int main() {
	srand((unsigned)time(nullptr));
	int isEvenOrOdd = 0;
	int isYesOrNo = 1;	

	std::function<void()> diceGameResult = [&]() {
		int diceNum = rand() % 2;

		if (diceNum == 0) {
			printf_s("出目は丁\n");
		}
		else if (diceNum == 1) {
			printf_s("出目は半\n");
		}

		if (isEvenOrOdd == diceNum) {
			printf_s("おめでとう! あなたは運があるね");
		}
		else if (isEvenOrOdd != diceNum) {
			printf_s("残念！ あなたは運がない");
		}
	};
	// 問います。
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

	SetTimeOut(diceGameResult, 3);

	return 0;
}