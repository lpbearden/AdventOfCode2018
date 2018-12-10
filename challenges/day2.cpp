#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <set>

void d2_part1();
void d2_part2();
int count_diffs(std::string a, std::string b);

int main() {
    std::cout << "Part 1: \n";
    d2_part1();
    std::cout << std::endl << "Part 2: \n";
    d2_part2();
}

void d2_part1() {
    int dupes, triplets = 0;

    std::ifstream infile("input.txt");

    std::string input;
    while (infile >> input) {
        std::set<char> searched_letters;
        bool found_dupe = false;
        bool found_trip = false;

        for (int i = 0; i < input.length(); i++) {
            int count = 0;
            if (searched_letters.find(input[i]) == searched_letters.end()) {
                searched_letters.insert(input[i]);
                count = std::count(input.begin(), input.end(), input[i]);
            }
            
            if (count == 3 && !found_trip) {
                triplets++;
                found_trip = true;
            }
            if (count == 2 && !found_dupe) {
                dupes++;
                found_dupe = true;
            }
        }
        searched_letters.clear();
    }

    std::cout << "The amount of triplets are: " << triplets << std::endl;
    std::cout << "The amount of duplicates are: " << dupes << std::endl;
    std::cout << "The checksum is: " << triplets * dupes << std::endl;
}

void d2_part2() {
    std::string input;
    std::set<std::string> inputs;
    std::string shared_chars;
    std::ifstream infile("input.txt");

    while (infile >> input) {
        inputs.insert(input);
    }

    for (std::string a : inputs) {
        for (std::string b : inputs) {
            if (1 == count_diffs(a, b)) {
                for (int i = 0; i < a.length(); i++) {
                    if (a[i] == b[i]) {
                        shared_chars += a[i];
                    }
                }
                std::cout << "Diff of 1" << " found for " << a << " " << b << std::endl;
                std::cout << "Shared characters: " << shared_chars << std::endl;
                return;
            }
        }
    }
}

int count_diffs(std::string a, std::string b) {
    int count=0;

    for (size_t i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) {
            count++;
        }
    }
    return count;
}