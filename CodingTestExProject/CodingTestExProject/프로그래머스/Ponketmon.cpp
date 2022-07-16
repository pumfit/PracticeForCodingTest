/*
* ���ϸ�
* https://school.programmers.co.kr/learn/courses/30/lessons/1845
* 
* Set ���� ����
**/
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    set<int> s;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums.size() / 2 == s.size())
            break;
        if (s.find(nums[i]) == s.end())
            s.insert(nums[i]);
    }
    return s.size();
}
/*
Vector���� Set���� �����ϱ�
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums) {
    unordered_set<int> s(nums.begin(), nums.end());

    return min(nums.size() / 2, s.size());
}
*/