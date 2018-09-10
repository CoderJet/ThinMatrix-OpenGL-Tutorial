#include "stdafx.h"
#include "Random.h"

Random::Random()
{
	m_rng.seed(std::random_device()());
}

float Random::randomFloat(float min, float max)
{
	std::uniform_int_distribution<std::mt19937::result_type> _return(min, max);
	return _return(m_rng);
}
