#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
        vector<int> nums;
        for (int i = 0; i < 7; i++) {
                int num;
                cin >> num;
                nums.push_back(num);
        }
        sort(nums.begin(), nums.end());
        cout << nums[0] << " " << nums[1] << " " << nums[6] - nums[1] - nums[0];
}