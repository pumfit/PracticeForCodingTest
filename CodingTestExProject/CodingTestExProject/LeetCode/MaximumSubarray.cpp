/*
ī���� �˰���

�ִ� �κ� ���� ���ϴ� ����
local_max[i] = max(A[i] + local_max[i-1], A[i])

ī���� �˰��� ���� ������
https://www.interviewbit.com/blog/maximum-subarray-sum/

����
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