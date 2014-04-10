#pragma once

namespace Syntax
{
	namespace Math
	{
		template<class T>
		class Color
		{
		public:
			Color(T _red, T _green, T _blue, T _alpha = 0)
			{
				red = _red;
				green = _green;
				blue = _blue;
				alpha = _alpha;
			}
			Color() : red(0), green(0), blue(0), alpha(0) {}

			T Red() const {return red;}
			void Red(T _red) {red = _red;}
			T Green() const {return green;}
			void Green(T _green) {green = _green;}
			T Blue() const {return blue;}
			void Blue(T _blue) {blue = _blue;}
			T Alpha() const {return alpha;}
			void Alpha(T _alpha) {alpha = _alpha;}			
			void Set(T _red, T _green, T _blue)
			{
				red = _red;
				green = _green;
				blue = _blue;
			}
		private:
			T red;
			T green;
			T blue;
			T alpha;
		};

		typedef Color<unsigned char> Color32;
		typedef Color<float> Color128;		

		inline Color32 Color16To32(unsigned short _arg)
		{
			return Color32(((_arg>>11) & 0x01f)<<3,((_arg>>5) & 0x03f)<<2,((_arg) & 0x01f)<<3);
		}
		inline unsigned short Color32To16(const Color32 &_arg)
		{
			return ((_arg.Red()&0x0f8)<<8) | ((_arg.Green()&0x0fc)<<3) | ((_arg.Blue()>>3)&0x01f);
		}
	}
}
