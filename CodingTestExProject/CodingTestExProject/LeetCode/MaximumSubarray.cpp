/*
카데인 알고리즘

최대 부분 합을 구하는 문제
local_max[i] = max(A[i] + local_max[i-1], A[i])

카데인 알고리즘 정리 포스팅
https://www.interviewbit.com/blog/maximum-subarray-sum/

문제
https://leetcode.com/problems/maximum-subarray/

*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int DP[100001] = { 0, };
        DP[0] = nums[0];
        int maxArr = DP[0];
        for (int i = 1; i < nums.size(); i++)
        {
            DP[i] = max(nums[i], nums[i] + DP[i - 1]);
            maxArr = max(maxArr, DP[i]);
        }
        return maxArr;

    }
};