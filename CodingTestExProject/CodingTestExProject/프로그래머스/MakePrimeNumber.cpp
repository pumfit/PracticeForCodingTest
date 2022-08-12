#include <vector>
#include <iostream>
using namespace std;

int answer = 0;
vector<int> v;
/*
소수 만들기

https://school.programmers.co.kr/learn/courses/30/lessons/12977
*/
int visited[51] = { 0, };
int arr[51] = { 0, };
int N = 0;

bool CheckPrimeNum(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void GetGroup(int depth, int n)
{
    if (depth == 3)
    {
        int sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum += v[arr[i]];
        }
        if (CheckPrimeNum(sum))
            answer++;
        return;
    }
    for (int i = n; i < N; i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            arr[depth] = i;
            GetGroup(depth + 1, i + 1);
            visited[i] = 0;
        }
    }
}

int solution(vector<int> nums) {
    N = nums.size();
    v.insert(v.begin(), nums.begin(), nums.end());
    GetGroup(0, 0);
    return answer;
}