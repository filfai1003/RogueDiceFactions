#include "math_utils.h"
#include <random>

static std::random_device rd;
static std::mt19937 gen(rd());

int randomInt(int min, int max) {
	std::uniform_int_distribution<> dis(min, max);
	return dis(gen);
}

float randomFloat(float min, float max) {
	std::uniform_real_distribution<float> dis(min, max);
	return dis(gen);
}

float distance(float x1, float y1, float x2, float y2) {
	float dx = x2 - x1;
	float dy = y2 - y1;
	return std::sqrt(dx * dx + dy * dy);
}