#include <stdio.h>


int Wage(int hour) {
	return 1072 * hour;
}

int Wage(int hour, int wage) {
	int result{};
	if (hour >= 1) {
		hour -= 1;
		if (wage == 0) {
			wage = 100;	
			printf_s("ノコリ %d ジカン,チンギン %d\n",hour, wage);

			result = Wage(hour, wage);
		}
		else {
			wage += (wage * 2) - 50;
			printf_s("ノコリ %d ジカン,チンギン %d\n", hour, wage);

			result = Wage(hour, wage);
		}
	}
	else {
		result = wage;
	}		
	return result;
}

int main() {
	int isWorkPatttarn = false;
	int hour = 0;
	printf_s("0 or 1 : ");
	scanf_s("%d\n", &isWorkPatttarn);

	printf_s("何時間働く? : ");
	scanf_s("%d 時間\n", &hour);
	if (isWorkPatttarn) {
		printf_s("%d", Wage(hour, 0));
	}
	else {
		printf_s("%d", Wage(hour));

	}

	return 0;
}