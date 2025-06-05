#include <iostream>
#include <vector>
using namespace std;
bool works(vector<vector<int>> schedule, int classroom_num, int floor, int period) {
        for (int i = 0; i < schedule.size(); i++) {
                if (schedule[i][period] == classroom_num) {
                        return false;
                }
        }
        if (classroom_num / 100 != floor) {
                return false;
        }
        return true;
}
int find_working_classroom(vector<vector<int>> schedule, vector<int> classroom_num, int floor, int period) {
        for (int j = 0; j < classroom_num.size(); j++) {
                if (works(schedule, classroom_num[j], floor, period)) {
                        return classroom_num[j];
                }
        }
        return 0;
}
void solve() {
        int groups, classrooms;
        cin >> groups >> classrooms;
        vector<int> classroom_num(classrooms);
        vector<int> classroom_floor(classrooms);
        for (int i = 0; i < classrooms; ++i) {
                cin >> classroom_num[i];
                classroom_floor[i] = classroom_num[i] / 100;
        }
        int min_floor, max_floor;
        for (int i = 0; i < classrooms; ++i) {
                if (i == 0 || classroom_floor[i] < min_floor) {
                        min_floor = classroom_floor[i];
                }
                if (i == 0 || classroom_floor[i] > max_floor) {
                        max_floor = classroom_floor[i];
                }
        }
        vector<vector<int>> schedule(groups, vector<int>(6));
        for (int i = 0; i < groups; i++) {
                if (i % 2 == 0 || (i % 2 != 0 && schedule[i - 1][0] == schedule[i - 1][1])) {
                        schedule[i][0] = find_working_classroom(schedule, classroom_num, min_floor, 0);
                        if (schedule[i][0] == 0) {
                                schedule[i][0] = find_working_classroom(schedule, classroom_num, max_floor, 0);
                        }
                        if (schedule[i][0] == 0) {
                                for (int floor = min_floor + 1; floor < max_floor; floor++) {
                                        schedule[i][0] = find_working_classroom(schedule, classroom_num, floor, 0);
                                        if (schedule[i][0] != 0) {
                                                break;
                                        }
                                }
                        }
                        if (schedule[i][0] / 100 == min_floor) {
                                for (int floor = max_floor; floor >= min_floor; floor--) {
                                        schedule[i][1] = find_working_classroom(schedule, classroom_num, floor, 1);
                                        if (schedule[i][1] != 0) {
                                                break;
                                        }
                                }
                        }
                        else if (schedule[i][0] / 100 == max_floor) {
                                for (int floor = min_floor; floor <= max_floor; floor++) {
                                        schedule[i][1] = find_working_classroom(schedule, classroom_num, floor, 0);
                                        if (schedule[i][1] != 0) {
                                                break;
                                        }
                                }
                        }
                        else {
                                int floor = schedule[i][0] / 100;
                                if (floor - min_floor < max_floor - floor) {
                                        for (int f = max_floor; f >= min_floor; f--) {
                                                schedule[i][1] = find_working_classroom(schedule, classroom_num, f, 0);
                                                if (schedule[i][1] != 0) {
                                                        break;
                                                }
                                        }
                                }
                                else {
                                        for (int f = min_floor; f <= max_floor; f++) {
                                                schedule[i][1] = find_working_classroom(schedule, classroom_num, f, 0);
                                                if (schedule[i][1] != 0) {
                                                        break;
                                                }
                                        }
                                }
                        }
                }
                else {
                        schedule[i][0] = schedule[i - 1][1];
                        schedule[i][1] = schedule[i - 1][0];
                }
                schedule[i][2] = schedule[i][0];
                schedule[i][3] = schedule[i][1];
                schedule[i][4] = schedule[i][0];
                schedule[i][5] = schedule[i][1];
                cout << schedule[i][0] << " " << schedule[i][1] << " " << schedule[i][2] << " " << schedule[i][3] << " " << schedule[i][4] << " " << schedule[i][5] << "\n";
        }
}
int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int t;
        cin >> t;
        while (t--) {
                solve();
        }
}