/*
ID: macos141
TASK: friday
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
bool isLeap(int year) {
        if (year % 400 == 0) {
                return true;
        }
        if (year % 100 == 0) {
                return false;
        }
        if (year % 4 == 0) {
                return true;
        }
        return false;
}
int main() {
        ifstream fin ("friday.in");
        ofstream fout ("friday.out");
        int years;
        fin >> years;
        int endyear = 1900 + years - 1;
        enum day {
                Saturday,
                Sunday,
                Monday,
                Tuesday,
                Wednesday,
                Thursday,
                Friday
        };
        enum month {
                January,
                February,
                March,
                April,
                May,
                June,
                July,
                August,
                September,
                October,
                November,
                December
        };
        enum day curday = Wednesday;
        vector<int> distrib;
        for (int i = 0; i < 7; i++) {
                distrib.push_back(0);
        }
        for (int year = 1900; year <= endyear; year++) {
                for (enum month curmonth = January; curmonth <= December; curmonth = (month) ((int) (curmonth) + 1)) {
                        int numdays;
                        if (curmonth == October || curmonth == May || curmonth == July || curmonth == December) {
                                numdays = 30 % 7;
                        }
                        else if (curmonth == March && isLeap(year)) {
                                numdays = 29 % 7;
                        }
                        else if (curmonth == March && !isLeap(year)) {
                                numdays = 28 % 7;
                        }
                        else {
                                numdays = 31 % 7;
                        }
                        curday = (day) (((int) (curday) + numdays) % 7);
                        distrib[curday]++;
                }
        }
        fout << distrib[Saturday] << " " << distrib[Sunday] << " " << distrib[Monday] << " " << distrib[Tuesday] << " " << distrib[Wednesday] << " " << distrib[Thursday] << " " << distrib[Friday] << "\n";
}