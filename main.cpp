#include <stdio.h>

class IShape {
public:
	IShape() {};
	~IShape() {};

	virtual void size() = 0;

	virtual void draw() = 0;
protected:
	float radius_ = 0.0f;
	float area_ = 0.0f;
};

class Circle : public IShape {
public:
	Circle(float rad) { radius_ = rad; };
	~Circle() {};

	void size() override { area_ = radius_ * radius_ * 3.14f; };

	void draw() override { printf_s("円 : 面積は %f です\n", area_); };
};

class Rectangle : public IShape {
public:
	Rectangle(float rad) { radius_ = rad; };
	~Rectangle() {};

	void size() override { area_ = (radius_ * 2) * (radius_ * 2); };

	void draw() override { printf_s("矩形 : 面積は %f です\n", area_); };
};

int main() {
	IShape* shapes[2];
	shapes[0] = new Circle(5.0f);
	shapes[1] = new Rectangle(5.0f);

	for (int i = 0; i < 2; i++) {
		shapes[i]->size();
		shapes[i]->draw();
		printf_s("\n");
	}


	return 0;
}