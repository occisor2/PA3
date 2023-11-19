#include <cmath>
#include "protocols.h"

size_t PA3::linear(size_t windowSize)
{
	return windowSize + 1;
}

size_t PA3::binaryExp(size_t windowSize)
{
	return windowSize * 2;
}

size_t PA3::logLog(size_t windowSize)
{
	using std::log2;
        
	auto w = windowSize;	
	auto newWinSize = std::floor((1 + (1 / log2(log2(w)))) * w);
		
	return newWinSize;
}
