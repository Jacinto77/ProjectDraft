#include "Random.h"

namespace Random
{
    int Random::get(int min, int max)
    {
        // initialize mersenne twister with std::random_device
        std::mt19937 mt{ std::random_device{}() };

        std::uniform_int_distribution<int> die{ min, max };
        return die(mt);
    }
}
