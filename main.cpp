#include <iostream>
#include <random> // Required header for modern random number generation

int main() {
    // 1. Create a random device to seed the generator with hardware entropy
    std::random_device rd;

    // 2. Initialize the standard Mersenne Twister engine with the seed
    std::mt19937 gen(rd());


    // 3. Define your range [min, max] inclusive
    int min_val = 1;
    int max_val = 100;
    std::uniform_int_distribution<int> distrib(min_val, max_val);

    // 4. Generate the random number
    int random_num = distrib(gen);

    std::cout << "Random number between 1 and 100: " << random_num << std::endl;

    return 0;
}

