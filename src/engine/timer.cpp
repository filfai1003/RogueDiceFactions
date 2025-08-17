#include "timer.h"
#include <chrono>

static std::chrono::steady_clock::time_point startTime;
static std::chrono::steady_clock::time_point stopTime;
static bool running = false;

void startTimer() {
	startTime = std::chrono::steady_clock::now();
	running = true;
}

void stopTimer() {
	stopTime = std::chrono::steady_clock::now();
	running = false;
}

uint32_t getElapsedMilliseconds() {
	if (running) {
		auto now = std::chrono::steady_clock::now();
		return static_cast<uint32_t>(std::chrono::duration_cast<std::chrono::milliseconds>(now - startTime).count());
	} else {
		return static_cast<uint32_t>(std::chrono::duration_cast<std::chrono::milliseconds>(stopTime - startTime).count());
	}
}

bool hasElapsed(uint32_t ms) {
	return getElapsedMilliseconds() >= ms;
}