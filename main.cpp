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
	int intA = 50, intB = 23;
	float floatA = 39.0f, floatB = 85.5f;
	double doubleA = 26.0, doubleB = 26.0;
	char charA = 'A', charB = 'G';
	
	// int	
	int intAB = Min<int>(intA, intB);
	printf_s("int Min(%d, %d) : %d\n", intA, intB, intAB);

	// float	
	float floatAB = Min<float>(floatA, floatB);
	printf_s("float Min(%0.2f, %0.2f) : %0.2f\n", floatA, floatB, floatAB);

	// double
	double doubleAB = Min<double>(doubleA, doubleB);
	printf_s("double Min(%0.2lf, %0.2lf) : %0.2lf\n", doubleA, doubleB, doubleAB);

	// char	
	Min<char>(charA, charB);

	return 0;
}