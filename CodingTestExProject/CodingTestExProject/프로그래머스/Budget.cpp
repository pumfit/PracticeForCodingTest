/*
* ¿¹»ê
https://school.programmers.co.kr/learn/courses/30/lessons/12982
*/
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());
    int i = 0;
    while (true)
    {
        if (answer == d.size())
            break;
        budget -= d[answer];
        if (budget >= 0)
            answer++;
        else
            break;
    }
    return answer;
}