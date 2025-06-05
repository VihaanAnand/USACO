#include <fstream>
#include <iostream>
using namespace std;
int main() {
        ifstream fin("promote.in");
        ofstream fout("promote.out");
        int bronze_before, bronze_after;
        fin >> bronze_before >> bronze_after;
        int silver_before, silver_after;
        fin >> silver_before >> silver_after;
        int gold_before, gold_after;
        fin >> gold_before >> gold_after;
        int platinum_before, platinum_after;
        fin >> platinum_before >> platinum_after;
        int gold_to_platinum = platinum_after - platinum_before;
        int silver_to_gold = gold_after - gold_before + gold_to_platinum;
        int bronze_to_silver = silver_after - silver_before + silver_to_gold;
        fout << bronze_to_silver << "\n" << silver_to_gold << "\n" << gold_to_platinum;
}