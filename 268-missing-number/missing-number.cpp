class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2; // Sum of 0..n
        int actualSum = 0;
        for (int x : nums) actualSum += x;
        return expectedSum - actualSum;
    }
};