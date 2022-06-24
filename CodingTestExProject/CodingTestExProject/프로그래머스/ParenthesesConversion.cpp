/*
괄호 변환
2020 KAKAO BLIND RECRUITMENT

https://programmers.co.kr/learn/courses/30/lessons/60058

문제 이해 자체를 못해서 꽤나 걸렸고 결국 다른 풀이 찾아봤던 문제
완전 재귀적 문제로 주석대로 풀어나가면 바로 풀리는 문제이긴하다.

처음에 이해가 안가던 부분이
//2. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다.
아니 그래서 u랑 v를 어떻게 나누고 그걸 다음 계산으로 반복하지 였는데 이부분 전체를 재귀로 만들면 해결할 수 있었다.
처음에 그냥 볼때 스택으로 괄호 판단만하면 될 줄 알았는데 생각보다 오래걸린 문제

+) u 구할때 초기화하는 방식이 좀 더 깔끔할 수 있을 것 같긴한다
처음에 초기화할때 isBalance에서 true로 반환되어서 그냥 . 넣긴했는데
그리고 인덱스도 1부터 하지않고 2부터 시작해도 될 것 같다 결국 균형잡힌 문자열이려면 2배수여야 하니
*/

#include <string>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

bool isBalance(string str)
{
    int cnt = 0;
    for (int i = 0; i < str.size(); i++)
        cnt += str[i] == '(' ? 1 : -1;
    return cnt == 0 ? true : false;
}

bool isCorrect(string str)
{
    stack<int> s;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
            s.push(1);
        else
        {
            if (s.empty())
                return false;
            else
                s.pop();
        }
    }
    return true;
}

string func(string p)
{
    //1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다. 
    if (p == "")
        return p;
    //2. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다. 
    int idx = 1;
    string u = "."; string v = "";
    while (!isBalance(u))
    {
        u = p.substr(0, idx);
        v = p.substr(idx, p.size() - idx);//빈문자열 가능
        idx++;
    }
    //3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다.
    if (isCorrect(u))
    {
        return u + func(v);//v에 대해 1단계부터 다시 수행합니다.
    }
    else
    {
        string temp = "(";// 4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다.
        // 4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다. 
        temp += func(v);
        // 4-3. ')'를 다시 붙입니다. 
        temp += ")";
        // 4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다. 
        for (int i = 1; i < u.size() - 1; i++)
        {
            temp += u[i] == '(' ? ')' : '(';
        }
        return temp;
    }
}

string solution(string p) {
    string answer = "";
    answer = func(p);
    return answer;
}