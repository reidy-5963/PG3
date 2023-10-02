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
	int A = 50, B = 23;
	float C = 39.0f, D = 85.5f;
	double E = 26.0, F = 62.0;
	char G = 'A', H = 'G';
	
	// int
	printf_s("int Min(%d, %d) : ", A, B);
	int AB = Min<int>(A, B);
	printf_s("%d\n", AB);

	// float
	printf_s("float Min(%0.2f, %0.2f) : ", C, D);
	float CD = Min<float>(C, D);

	printf_s("%0.2f\n", CD);

	// double
	printf_s("double Min(%0.2lf, %0.2lf) : ", E, F);	
	double EF = Min<double>(E, F);
	printf_s("%0.2lf\n", EF);

	// char
	printf_s("char Min(%c, %c) : ", G, H);
	char GH = Min<char>(G, H);
	printf_s("%c\n", GH);


	return 0;
}