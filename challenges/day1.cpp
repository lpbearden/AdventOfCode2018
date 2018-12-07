#include <iostream>
#include <fstream>
#include <set>

void d1_part1();
void d1_part2();

int main() {
    d1_part1();
    d1_part2();
}

void d1_part1() {
    std::ifstream infile("input.txt");

    int init;
    int frequency = 0;
    while (infile >> init) {
        frequency += init;
    }

    std::cout << "Part 1: \n\tThe frequency should be: " << frequency << std::endl;
}

void d1_part2() {
    std::ifstream infile("input.txt");

    int init;
    std::set<int> frequencies;
    bool dupe_found = false;
    int frequency = 0;

    while (!dupe_found) {
        while (infile >> init) {
            frequency += init;
            if(frequencies.find(frequency) != frequencies.end()) {
                std::cout << "Part 2: \n\tDupe frequency found: " << frequency;
                dupe_found = true;
                break;
            }
            frequencies.insert(frequency);
        }
        infile.clear();
        infile.seekg(0, std::ios::beg);
    }
}