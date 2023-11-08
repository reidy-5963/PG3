#include <stdio.h>

template <typename T1, typename T2>

class ClassTemp {
public:
	T1 numA_;
	T2 numB_;

	ClassTemp(T1 numA, T2 numB) : numA_(numA), numB_(numB) {}

	T1 Min() {
		if (numA_ >= numB_) {
			return static_cast<T1>(numB_);
		}
		else {
			return static_cast<T1>(numA_);
		}
	}

};

int main() {
	ClassTemp<int, int> min_i2i(20, 21);
	ClassTemp<float, float> min_f2f(20.0f, 20.1f);
	ClassTemp<double, double> min_d2d(20.13, 20.2);
	ClassTemp<float, int> min_f2i(20.2f, 20);
	ClassTemp<double, int> min_d2i(20.6, 21);
	ClassTemp<double, float> min_d2f(20.1, 20.12f);


	printf_s("int (%d), int (%d)\n Min = %d\n\n",min_i2i.numA_, min_i2i.numB_, min_i2i.Min());
	printf_s("float (%.2f), float (%.2f)\n Min = %.2f\n\n", min_f2f.numA_, min_f2f.numB_, min_f2f.Min());
	printf_s("double (%.2lf), double (%.2lf)\n Min = %.2lf\n\n", min_d2d.numA_, min_d2d.numB_, min_d2d.Min());
	printf_s("float (%.2f), int (%d)\n Min = %.2f\n\n", min_f2i.numA_, min_f2i.numB_, min_f2i.Min());
	printf_s("double (%.2lf), int (%d)\n Min = %.2lf\n\n", min_d2i.numA_, min_d2i.numB_, min_d2i.Min());
	printf_s("double (%.2lf), float (%.2f)\n Min = %.2lf\n\n", min_d2f.numA_, min_d2f.numB_, min_d2f.Min());
	return 0;
}