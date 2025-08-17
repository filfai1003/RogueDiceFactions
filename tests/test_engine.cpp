#include "../src/engine/math_utils.h"
#include "../src/engine/timer.h"
#include <iostream>

int main() {
    std::cout << "Testing math_utils..." << std::endl;
    int ri = randomInt(1, 6);
    float rf = randomFloat(0.0f, 1.0f);
    float dist = distance(0.0f, 0.0f, 3.0f, 4.0f);
    std::cout << "randomInt(1,6): " << ri << std::endl;
    std::cout << "randomFloat(0,1): " << rf << std::endl;
    std::cout << "distance(0,0,3,4): " << dist << std::endl;

    std::cout << "Testing timer..." << std::endl;
    startTimer();
    for (volatile int i = 0; i < 10000000; ++i) {} // busy wait
    stopTimer();
    uint32_t elapsed = getElapsedMilliseconds();
    std::cout << "Elapsed ms: " << elapsed << std::endl;
    std::cout << "Has elapsed 1 ms? " << (hasElapsed(1) ? "Yes" : "No") << std::endl;
    return 0;
}
