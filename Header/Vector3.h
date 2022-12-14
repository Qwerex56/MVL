#pragma once
#ifndef _Vector2_
#define _Vector2_

#include <stdexcept>
#include <iostream>

namespace mvl {
	template <typename T>
	class Vector3 {
	private:
		T x;
		T y;
		T z;
	public:		
		Vector3<T>();

		Vector3<T>(T x, T y, T z = 0);

		Vector3<T>(const Vector3&);

		Vector3<T>(const Vector3&&);

		inline T X() { return this->x; }
		inline T Y() { return this->y; }
		inline T Z() { return this->z; }

		Vector3<T> operator+(const Vector3<T>& rhs);

		Vector3<T> operator-(const Vector3<T>& rhs);

		Vector3<T> operator*(const Vector3<T>& rhs);

		Vector3<T> operator*(const T);

		Vector3<T> operator/(const Vector3<T>&);

		Vector3<T> operator/(const T);

		Vector3<T> operator=(const Vector3<T>& rhs) {
			this->x = rhs.x;
			this->y = rhs.y;
			this->z = rhs.z;
			return *this;
		}

		friend Vector3<T> operator+=(Vector3<T>& lhs, const Vector3<T>& rhs) {
			return lhs = lhs + rhs;
		}

		friend Vector3<T> operator-=(Vector3<T>& lhs, const Vector3<T>& rhs) {
			return lhs = lhs - rhs;
		}

		friend Vector3<T> operator*=(Vector3<T>& lhs, const Vector3<T>& rhs) {
			return Vector3<T>(/*kto wie*/);
		}

		friend Vector3<T> operator*=(Vector3<T>& lhs, const T scalar) {
			return lhs = lhs * scalar;
		}

		friend Vector3<T> operator/=(Vector3<T>& lhs, const Vector3<T>& rhs) {
			return Vector3<T>(/*kto wie*/);
		}

		friend Vector3<T> operator/=(Vector3<T>& lhs, const T scalar) {
			return lhs = lhs * (1 / scalar);
		}
		
		friend Vector3<T> operator/=(const T scalar, Vector3<T>& lhs) {
			return lhs = lhs * (1 / scalar);
		}

		inline static void Print(const Vector3<T>& vec) {
			std::cout << "x: " << vec.x << " y: " << vec.y << " z: " << vec.z << std::endl;
		}

		//TODO:
		// Logic operators
		constexpr friend bool operator <=(Vector3<T>& lhs, const Vector3<T>& rhs) {
			if (lhs.X() <= rhs.X() && lhs.Y() <= rhs.Y() && lhs.Z() <= rhs.Z()) {
				return true;
			}
			else return false;
		}
		constexpr friend bool operator >=(Vector3<T>&, const Vector3<T>&) {
			if (lhs.X() >= rhs.X() && lhs.Y() >= rhs.Y() && lhs.Z() >= rhs.Z()) {
				return true;
			}
			else return false;
		}
		constexpr friend bool operator < (Vector3<T>&, const Vector3<T>&) {
			if (lhs.X() < rhs.X() && lhs.Y() < rhs.Y() && lhs.Z() < rhs.Z()) {
				return true;
			}
			else return false;
		}
		constexpr friend bool operator > (Vector3<T>&, const Vector3<T>&) {
			if (lhs.X() > rhs.X() && lhs.Y() > rhs.Y() && lhs.Z() > rhs.Z()) {
				return true;
			}
			else return false;
		}
		constexpr friend bool operator ==(Vector3<T>&, const Vector3<T>&) {
			if (lhs.X() == rhs.X() && lhs.Y() == rhs.Y() && lhs.Z() == rhs.Z()) {
				return true;
			}
			else return false;
		}
		constexpr friend bool operator !=(Vector3<T>&, const Vector3<T>&) {
			if (lhs.X() != rhs.X() && lhs.Y() != rhs.Y() && lhs.Z() != rhs.Z()) {
				return true;
			}
			else return false;
		}

		//Array like getter,
		//throws out of range exception for numbers bigger than 2
		T operator[](size_t id) const;

		//Returns new vector with all components in absolute values. Doesnt change components
		constexpr Vector3<T> Abs() const;

		//Returns squared length of an vector
		constexpr T LengthSquared() const;

		//Returns length of an vector.
		//Use length squared for faster computing
		constexpr T Length() const;
		
		//Returns vector normal
		constexpr Vector3<T> Normal() const;

		//Returns and sets vectors length to 1
		constexpr Vector3<T> Normalize();

		//Rotates a vector by given angle in radians
		constexpr Vector3<T> Rotate(float angle);

		//Rotates a vector counter clockwise by given radian
		constexpr Vector3<T> RotateC(float angle);

		//Returns dot of an two vectors
		constexpr T Dot(const Vector3<T>&) const;

		//Returns dot product of an two vectors
		constexpr T DotProduct(const Vector3<T>&) const;

		//Returns cross of an two vectors
		constexpr T Cross(const Vector3<T>&) const;

		//Returns cross product
		constexpr T CrossProduct(const Vector3<T>&) const;
	};
	typedef Vector3<int> Vector3i;
	typedef Vector3<float> Vector3f;

	//2D representatiion of Vector3D
	template<typename T>
	class Vector2 : Vector3<T> {

	};
	typedef Vector2<int> Vector2i;
	typedef Vector2<float> Vector2f;
}

#endif // !Vector2
