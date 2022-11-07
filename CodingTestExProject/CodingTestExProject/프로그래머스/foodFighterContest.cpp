/*
https://school.programmers.co.kr/learn/courses/30/lessons/134240
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    for(int i =1;i<food.size();i++)
    {
        for(int j = 0;j<food[i]/2; j++)
        {
            answer += i+'0';
        }
    }
     answer += '0';
    for(int i = answer.size()-1;i>0;i--)
    {
        answer += answer[i-1];
    }
    return answer;
}