#pragma once

namespace Syntax
{
	namespace Math
	{
		template<class T>
		class Vector4
		{
		public:
			Vector4(void) : x(0), y(0), z(0), w(0) {}
			Vector4(T _x, T _y, T _z, T _w) : x(_x), y(_y), z(_z), w(_w) {}
			~Vector4(void) {}
			T X() const {return x;}
			void X(T _x) {x=_x;}
			T Y() const {return y;}
			void Y(T _y) {y=_y;}
			T Z() const {return z;}
			void Z(T _z) {z=_z;}
			T W() const {return w;}
			void W(T _w) {w=_w;}
		private:
			T x;
			T y;
			T z;
			T w;
		};

		typedef Vector4<float> Vector4F;
		typedef Vector4<double> Vector4D;
		typedef Vector4<int> Vector4I;
	}
}
