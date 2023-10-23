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

int RundomDice() {
	return 1 + rand() % 2;
}

void setTimeout(std::function<void(int)> *p, int second, int answer) {
	Sleep(second * 1000);
	
	p(answer);
}

void DiceGame(int answer) {
}

int main() {
	srand((unsigned)time(nullptr));
	int isEvenOrOdd = 0;
	int isYesOrNo = int(Answer::No);
	std::function<void(int)> pFunc = [](int answer) {
		int check = 0;
		int diceNum = RundomDice();

		if (check == int(Dice::Even)) {
			printf_s("出目は丁\n");
		}
		else if (check == int(Dice::Odd)) {
			printf_s("出目は半\n");
		}

		if (answer == check) {
			printf_s("おめでとう! あなたは運があるね");
		}
		else if (answer != check) {
			printf_s("残念！ あなたは運がない");
		}

	}



	for (; isYesOrNo == int(Answer::No);) {
		printf_s("丁(偶数)か半(奇数)か\n丁なら0を、半なら1を押してください\n");
		scanf_s("%d", &isEvenOrOdd);
		for (; (isEvenOrOdd < int(Dice::Even) || isEvenOrOdd > int(Dice::Odd));) {
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


	
	setTimeout(&pFunc, 3, isEvenOrOdd);

	return 0;
}