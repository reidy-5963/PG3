#include <stdio.h>

template <typename T1, typename T2>

class Calc {
public:
	T1 numA_;
	T2 numB_;

	Calc(T1 numA, T2 numB) : numA_(numA), numB_(numB) {}

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
	Calc<int, int> min_int2int(20, 21);
	Calc<float, float> min_float2float(20.0f, 20.1f);
	Calc<double, double> min_double2double(20.13, 20.2);
	Calc<float, int> min_float2int(20.2f, 20);
	Calc<double, int> min_double2int(20.6, 21);
	Calc<double, float> min_double2float(20.1, 20.12f);


	printf_s("int (%d), int (%d)\n Min = %d\n\n", min_int2int.numA_, min_int2int.numB_, min_int2int.Min());
	printf_s("float (%.2f), float (%.2f)\n Min = %.2f\n\n", min_float2float.numA_, min_float2float.numB_, min_float2float.Min());
	printf_s("double (%.2lf), double (%.2lf)\n Min = %.2lf\n\n", min_double2double.numA_, min_double2double.numB_, min_double2double.Min());
	printf_s("float (%.2f), int (%d)\n Min = %.2f\n\n", min_float2int.numA_, min_float2int.numB_, min_float2int.Min());
	printf_s("double (%.2lf), int (%d)\n Min = %.2lf\n\n", min_double2int.numA_, min_double2int.numB_, min_double2int.Min());
	printf_s("double (%.2lf), float (%.2f)\n Min = %.2lf\n\n", min_double2float.numA_, min_double2float.numB_, min_double2float.Min());
	return 0;
}