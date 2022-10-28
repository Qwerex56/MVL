#include <iostream>
#include "Vector3.h"
#include "Vector3.cpp"

int main() {
	using namespace mvl;
	Vector3f v1{ 2 , 3 , 5 };
	Vector3f v2{ 1 , 1 , 1 };

	Vector3f::Print(v1);
	Vector3f::Print(v2);
	Vector3f::Print(v1 + v2);
	Vector3f::Print(v1 - v2);
	Vector3f::Print(v1 * 2);
	//Vector3f::Print(2 * v1);
	Vector3f::Print(v1 / 2);

	Vector3f::Print(v1 += v2);
	Vector3f::Print(v1 -= v2);
	Vector3f::Print(v1 *= 2);
	Vector3f::Print(v1 /= 2);

	return 0;
}