#include <iostream>
#include "Vector3.h"
#include "Vector3.cpp"

int main() {
	using namespace mvl;
	Vector3f v1;
	v1 += Vector3f{ 1, 1, 1 };
	Vector3f::Print(v1);
	return 0;
}