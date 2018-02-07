#ifndef _H_MATH_CMN_H_
#define _H_MATH_CMN_H_

#include <cmath>
#include <float.h>
#include <algorithm>

namespace octoon
{
	namespace math
	{
		void randomize();
		void randomize(unsigned int);
		int random(int min, int max);
		float random(float min, float max);
		double random(double min, double max);

		std::uint32_t morton2(std::uint32_t x, std::uint32_t y);
		std::uint32_t morton3(std::uint32_t x, std::uint32_t y, std::uint32_t z);
	}
}

#endif