#include <stdio.h>

// 関数テンプレート
template <typename Type>
Type Min(Type a, Type b) {
	return static_cast<Type>(a <= b ? a : b);
}
// charのみ別の対応
template <>
char Min(char a, char b) {
	printf_s("数字以外は代入できません(入力された文字 %c, %c)\n", a, b);
	return 0;
}

int main() {
	int iA = 50, iB = 23;
	float fA = 39.0f, fB = 85.5f;
	double dA = 26.0, dB = 62.0;
	char cA = 'A', cB = 'G';
	
	// int
	printf_s("int Min(%d, %d) : ", iA, iB);
	printf_s("%d\n", Min<int>(iA, iB));

	// float
	printf_s("float Min(%0.2f, %0.2f) : ", fA, fB);
	printf_s("%0.2f\n", Min<float>(fA, fB));

	// double
	printf_s("double Min(%0.2lf, %0.2lf) : ", dA, dB);
	printf_s("%0.2lf\n", Min <double>(dA, dB));

	// char
	printf_s("char Min(%c, %c) : ", cA, cB);
	printf_s("%c\n", Min<char>(cA, cB));


	return 0;
}