/*
가장 큰 수

https://programmers.co.kr/learn/courses/30/lessons/42746

이문제는 이번에 처음 푼문제 아니고 이전에도 했었는데 3번 테케가 너무 이해가 가지 않았다.

난 이문제 테케를 이해를 못해서 지나갔었다.

실행한 결괏값 "353333323021000"이(가) 기댓값 "353233333021000"와(과) 다릅니다.
아니 353333323021000이 353233333021000보다 큰게 맞지 않나..? 이문제 가장 큰 수 찾는게 아니였나??생각하고 넘겼는데
어이없게도 테케가 틀려도 통과할 수 있는 문제였다.

정렬을 하는 방식은 string으로 두값을 더했을 때 더 큰 값을 반환하면 되고 이 경우 00이거나 000등이 포함되어 있을 수 도 있으므로
맨 앞자리가 0인 경우는 0을 반환해주면 되는 문제이다.
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string& A, string& B)
{
    return A + B > B + A;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for (int i = 0; i < numbers.size(); i++)
        v.push_back(to_string(numbers[i]));
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < numbers.size(); i++)
        answer += v[i];
    if (answer[0] == '0')
        return "0";
    return answer;
}