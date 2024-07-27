#include <iostream>
using namespace std;
int main() {
        int longest = 0;
        int current = 0;
        char latest = 'd';
        string dna;
        cin >> dna;
        for (char letter : dna) {
                if (letter == latest) {
                        current++;
                }
                else {
                        current = 1;
                }
                latest = letter;
                if (current > longest) {
                        longest = current;
                }
        }
        cout << longest;
}