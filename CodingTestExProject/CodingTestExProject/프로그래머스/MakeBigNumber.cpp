/*
큰 수 만들기
https://programmers.co.kr/learn/courses/30/lessons/42883

idx를 0으로 초기화하고 풀었다가 테케 3개 통과 못해가지고 뭐지 싶었던 문제
생각해보니 19번 라인에서 idx +1을 해줘서 기본 테케처럼 맨 처음수가 선택되지 않는 예제가 아닌
0번 인덱스가 선택되는경우들이 빠지고 있었다.
값 초기화 조심하자

이 문제는 전체 탐색으로 시간초과 한번 났었는데 생각보다 저 탐색 범위 지정하는게 맞는 로직인지 생각해내기가 어려웠다.
탐욕법 문제 더 풀어보면서 익히는 게 좋을 것 같다.
*/
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int num = number.size() - k;
    int idx = -1;
    for (int i = 0; i < num; i++)
    {
        char max = ' ';
        for (int j = idx + 1; j <= k + i; j++)//탐색 범위
        {
            char n = number[j];
            if (n > max)
            {
                max = n;
                idx = j;
            }
        }
        answer.push_back(max);
    }
    return answer;
}