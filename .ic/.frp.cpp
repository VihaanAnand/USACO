#include <iostream>
#include <string>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

size_t findRotationPoint(const vector<string>& words)
{
    size_t floorIndex = 0;
    size_t ceilingIndex = words.size() - 1;

    while (floorIndex < ceilingIndex) {

        // guess a point halfway between floor and ceiling
        size_t guessIndex = floorIndex + ((ceilingIndex - floorIndex) / 2);

        // if guess comes after first word or is the first word
        if (words[guessIndex] >= words[0]) {
            // go right
            floorIndex = guessIndex;
        }
        else {
            // go left
            ceilingIndex = guessIndex;
        }

        // if floor and ceiling have converged
        if (floorIndex + 1 == ceilingIndex) {

            // between floor and ceiling is where we flipped to the beginning
            // so ceiling is alphabetically first
            break;
        }
    }

    return ceilingIndex;
}


















// tests

const lest::test tests[] = {
    {CASE("small array") {
        const vector<string> words {"cape", "cake"};
        const size_t actual = findRotationPoint(words);
        const size_t expected = 1;
        EXPECT(actual == expected);
    }},
    {CASE("medium array") {
        const vector<string> words {"grape", "orange", "plum", "radish", "apple"};
        const size_t actual = findRotationPoint(words);
        const size_t expected = 4;
        EXPECT(actual == expected);
    }},
    {CASE("large array") {
        const vector<string> words {"ptolemaic", "retrograde", "supplant", "undulate",
            "xenoepist", "asymptote", "babka", "banoffee", "engender", "karpatka",
            "othellolagkage"};
        const size_t actual = findRotationPoint(words);
        const size_t expected = 5;
        EXPECT(actual == expected);
    }},
    {CASE("possibly missing edge case") {
        // are we missing any edge cases?

    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}