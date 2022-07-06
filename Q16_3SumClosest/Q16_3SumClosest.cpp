#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int currSum = 0, sum = INT_MIN;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
        int j = i + 1, k = nums.size() - 1;

        while (j < k) {
            currSum = nums[i] + nums[j] + nums[k];

            if (currSum == target) {
                return currSum;
            }

            if (abs((long)target - (long)currSum) < abs((long)target - (long)sum)) {
                sum = currSum;
            }

            if (currSum < target) {
                j++;
            }
            else if (currSum > target) {
                k--;
            }
        }
    }

    return sum;
}

int main()
{
    vector<int> nums = {0, 1, 2};

    cout << threeSumClosest(nums, 1);

    return 0;
}