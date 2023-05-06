#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(vector<int> &nums, int first, vector<int> &current, vector<vector<int>> &result) {
    if (current.size() == 7) {
        result.push_back(current);
        return;
    }

    for (int i = first; i < nums.size(); ++i) {
        current.push_back(nums[i]);
        backtrack(nums, i + 1, current, result);
        current.pop_back();
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> current;
    backtrack(nums, 0, current, result);
    return result;
}

int main() {
    vector<int> nums = {1, 1, 4, 4, 5, 5, 0};
    vector<vector<int>> permutations = permuteUnique(nums);

    for (auto &p : permutations) {
        for (int i : p) {
            cout << i;
        }
        cout << endl;
    }

    return 0;
}
