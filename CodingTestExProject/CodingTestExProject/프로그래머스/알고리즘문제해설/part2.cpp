/*
순열검사
https://school.programmers.co.kr/learn/courses/18/lessons/1877
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool solution(vector<int> arr)
{
    bool answer = true;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != i + 1)
        {
            answer = false;
            break;
        }
    }

    return answer;
}