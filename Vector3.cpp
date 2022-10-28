#include "Vector3.h"

namespace mvl {
	template<class T>
	Vector3<T>::Vector3<T>()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	template<class T>
	Vector3<T>::Vector3(T x, T y, T z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	template<typename T>
	Vector3<T>::Vector3(const Vector3& v3)
	{
		this->x = v3.x;
		this->y = v3.y;
		this->z = v3.z;
	}

	template<typename T>
	Vector3<T>::Vector3(const Vector3&& v3)
	{
		this->x = v3.x;
		this->y = v3.y;
		this->z = v3.z;
	}

	template<typename T>
	Vector3<T> Vector3<T>::operator+(const Vector3<T>& rhs)
	{
		return Vector3<T>(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);
	}

	template<typename T>
	Vector3<T> Vector3<T>::operator-(const Vector3<T>& rhs)
	{
		return Vector3<T>(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
	}

	template<typename T>
	Vector3<T> Vector3<T>::operator*(const Vector3<T>& rhs)
	{
		return Vector3<T>(/*kto wie?*/);
	}

	template<typename T>
	Vector3<T> Vector3<T>::operator*(const T scalar)
	{
		return Vector3<T>(this->x * scalar, this->y * scalar, this->z*scalar);
	}

	template<typename T>
	Vector3<T> Vector3<T>::operator/(const Vector3<T>& rhs)
	{
		return Vector3<T>(/*kto wie?*/);
	}

	template<typename T>
	Vector3<T> Vector3<T>::operator/(const T scalar)
	{
		return this * (1 / scalar);
	}

	template<typename T>
	T& Vector3<T>::operator[](size_t id) const
	{
		switch (id)
		{
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		default:
			throw std::out_of_range;
		}
	}

	template<typename T>
	constexpr Vector3<T> Vector3<T>::Abs() const
	{
		Vector3<T> ret{ this };
		try {
			for (size_t i = 0; i < std::numeric_limits<size_t>::max(); i++) {
				if (this[i] < 0) {
					ret = -this[i];
				}
				else {
					ret = this[i];
				}
			}
		}
		catch (std::out_of_range& err) {
			break;
		}
		return ret;
	}

	template<typename T>
	constexpr T Vector3<T>::LengthSquared() const
	{
		return x * x + y * y + z * z;
	}

	template<typename T>
	constexpr T Vector3<T>::Length() const
	{
		return sqrt(LengthSquared());
	}

	template<typename T>
	constexpr Vector3<T> Vector3<T>::Normalize()
	{
		this /= Length();
		return this;
	}

	template<typename T>
	Vector3<T> operator+=(const Vector3<T>& lhs, const Vector3<T>& rhs)
	{
		return Vector3<T>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
	}

	template<typename T>
	Vector3<T> operator-=(const Vector3<T>& lhs, const Vector3<T>& rhs)
	{
		return Vector3<T>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
	}

	template<typename T>
	Vector3<T> operator*=(const Vector3<T>& lhs, const Vector3<T>& rhs)
	{
		return Vector3<T>(/*kto wie*/);
	}

	template<typename T>
	Vector3<T> operator*=(const Vector3<T>& lhs, const T scalar)
	{
		return Vector3<T>(lhs.x * scalar, lhs.y * scalar, lhs.z * scalar);
	}

	template<typename T>
	Vector3<T> operator/=(const Vector3<T>& lhs, const Vector3<T>& rhs)
	{
		return Vector3<T>(/*kto wie*/);
	}

	template<typename T>
	Vector3<T> operator/=(const Vector3<T>& lhs, const T scalar)
	{
		return Vector3<T>(lhs * (1 / scalar));
	}


}