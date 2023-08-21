#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverse(vector<int>& nums, int i, int j) {
        while (i < j) {
            swap(nums[i++], nums[j--]);
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums, 0, n - 1);
        reverse(nums, k, n - 1);
        reverse(nums, 0, k - 1);
    }
};

int main() {
    Solution solution;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 3;
    solution.rotate(nums1, k1);
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums2 = {-1, -100, 3, 99};
    int k2 = 2;
    solution.rotate(nums2, k2);
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
