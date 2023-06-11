class Solution {
public:
    int maxArea(vector<int>& height) {
        int first = 0, last = height.size()-1;
        int maxWater = 0;
        while (first < last) {
            int curWater;
            int minimum = min(height[first], height[last]);
            curWater = minimum * (last-first);
            if (height[first] > height[last]) {
                last--;
            }else {
                first++;
            }
            if (curWater > maxWater) {
                maxWater = curWater;
            }
        }

        return maxWater;
    }
};