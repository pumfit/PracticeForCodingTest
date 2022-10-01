/*
최대공약수와 최소공배수

https://school.programmers.co.kr/learn/courses/30/lessons/12940
*/
#include <string>
#include <vector>

using namespace std;

int lcm(int a,int b)
{
    return  a%b==0?b:lcm(b%a,a);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.push_back(m>n?lcm(m,n):lcm(n,m));
    answer.push_back(n*m/answer[0]);
    return answer;
}