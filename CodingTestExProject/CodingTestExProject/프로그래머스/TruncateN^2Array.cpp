/*
n^2 배열 자르기

https://school.programmers.co.kr/learn/courses/30/lessons/87390

n의 크기가 10^7이므로 모두 구해서 자르는건 불가능해보였고 처음에 dp인가 싶다가 범위가 변경되므로 아니라고 판단했다.
그래서 규칙성을 찾기위해 left의 행 열을 구해보고 right 까지 출력해보았다. 이때 두 수 중 하나가 정답과 같다는 걸 발견했는데
행과 열 두 수 중 큰 값이 해당 칸의 값이 된다는 것을 알게되었다.

left값을 증가시켜가면서 1차원배열의 값을 채워주면 되는 문제이다.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int leftCol, leftRow;
    while (true)
    {
        if (left > right)
            break;
        leftCol = left % n + 1; leftRow = left / n + 1;
        answer.push_back(leftCol > leftRow ? leftCol : leftRow);
        left++;
    }
    return answer;
}