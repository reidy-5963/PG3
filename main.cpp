#include <stdio.h>


int Wage() {
	return 1072;
}

int Wage(int hour, int wage) {
	int result = 0;
	if (wage == 0) {
		result = 100;
	}
	else {
		result = wage * 2 - 50;
	}
	printf_s("%d\n", result);
	return Wage(hour - 1, result);
}

int main() {
	
	printf_s("%d", Wage(5, 0));

	return 0;
}