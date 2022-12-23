/*
https://school.programmers.co.kr/learn/courses/30/lessons/131128

예외 경우를 잘알려주는 친절한 문제
*/
#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    int numX[10] = {0,};
    int numY[10] = {0,};
    for(int i = 0;i<X.size();i++)
        numX[X[i]-'0']++;
    for(int i = 0;i<Y.size();i++)
        numY[Y[i]-'0']++;
    for(int i = 9;i>=0;i--)
    {
        if(numX[i]==0||numY[i]==0)
            continue;
        int n = numX[i]>numY[i]?numY[i]:numX[i];
        if(i==0&&answer=="")
        {
            answer+='0';
            break;
        }
        for(int j = 0;j<n;j++)
            answer+=(i+'0');
    }
    if(answer=="")
        answer = "-1";
    return answer;
}