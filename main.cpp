#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <functional>

typedef void (*PFunc)(int);

enum class Dice {
	Even = 1,	// 偶数
	Odd = 2		// 奇数
};

enum class Answer {
	Yes = 1,	// はい
	No = 2		// いいえ
};

//void DispResult(int* s) {
//	printf_s("%d秒まって実行されたよ\n", *s);
//}

void setTimeout(PFunc p, int second, int selectEvenorOdd) {
	Sleep(second * 1000);

	p(selectEvenorOdd);
}

int RundomDice() {
	return 1 + rand() % 2;
}

void DiceGame(int answer) {
	//int check = 0;
	int diceNum = RundomDice();

	// 出目が偶数なら0 奇数なら1
	//check = diceNum % 2;
	//printf_s("サイコロの出目 : %d\n", diceNum);
	//Sleep(1 * 1000);

	if (diceNum == int(Dice::Even)) {
		printf_s("出目は丁\n");
	}
	else if (diceNum == int(Dice::Odd)) {
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
	int isYesOrNo = int(Answer::No);
	std::function<void(int)> allFunction = [=](int isEvenOrOdd) {
		for (; isYesOrNo == int(Answer::No);) {
			printf_s("丁(偶数)か半(奇数)か\n丁なら1を、半なら2を押してください\n");
			scanf_s("%d", &isEvenOrOdd);
			for (; (isEvenOrOdd < int(Dice::Even) || isEvenOrOdd > int(Dice::Odd));) {
				printf_s("範囲外の回答です。もう一度お願いします。\n");
				scanf_s("%d", &isEvenOrOdd);

			}
			printf_s("ファイナルアンサー? はい : 1, いいえ : 2\n");
			scanf_s("%d", &isYesOrNo);
			for (; (isYesOrNo < int(Answer::Yes) || isYesOrNo > int(Answer::No));) {
				printf_s("範囲外の回答です。もう一度お願いします。\n");
				scanf_s("%d", &isYesOrNo);

			}
		}

		PFunc p;
		p = DiceGame;

		setTimeout(p, 3, isEvenOrOdd);
	};
	
	allFunction(isEvenOrOdd);
	return 0;
}