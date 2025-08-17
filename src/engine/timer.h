#pragma once
#include <cstdint>

void startTimer();
void stopTimer();
uint32_t getElapsedMilliseconds();
bool hasElapsed(uint32_t ms);
