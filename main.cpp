#include <stdio.h>

//enum class WorkPattern{
//	General,	// 一般
//	Recursion	// 再帰
//};

int CalcGeneralWage(int hour) {
	return 1072 * hour;
}

int CalcRecursiveWage(int hour, int wage) {
	int tmp = wage;
	if (hour > 0) {
		hour--;
		if (wage == 0) {
			wage = 100;
		}
		else {
			wage  = tmp * 2 - 50;
		}
		return tmp + CalcRecursiveWage(hour, wage);
	}
	return wage;
}

void WageComparison(int recursionWage, int generalWage) {
	if (recursionWage > generalWage) {
		int tmp = recursionWage - generalWage;
		printf_s("再帰的な賃金の方が %d 円高い\n", tmp);
	}
	else if (generalWage > recursionWage) {
		int tmp = generalWage - recursionWage;
		printf_s("一般的な賃金の方が %d 円高い\n", tmp);
	}
	else {
		printf_s("どちらも同じ賃金をもらえる\n");
	}
}
int main() {
	int hour = 0;

	printf_s("何時間働きますか?(少数は切り捨てられます) : ");
	scanf_s("%d", &hour);
	for (; hour < 0;) {
		if (hour < 0) {
			printf_s("範囲外です。負の数は入力できません。");
			scanf_s("%d", &hour);
		}
	}

	int recursionWage = CalcRecursiveWage(hour, 0);
	printf_s("再帰的な賃金体系\n");
	printf_s("%d 円\n\n", recursionWage);

	int generalWage = CalcGeneralWage(hour);
	printf_s("一般敵な賃金体系\n");
	printf_s("%d 円\n\n", generalWage);

	// どちらの賃金体系がいいのかの比較
	WageComparison(recursionWage, generalWage);

	return 0;
}