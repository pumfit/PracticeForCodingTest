/*
카펫
https://school.programmers.co.kr/learn/courses/30/lessons/42842


아주 약간의 수학문제

다른 풀이 보면 이차방정식으로 푸는 풀이도 있어서 신기했다.
뭔가 다른 풀이들보면 곱이 되는 두 수를 정해두고 찾는 풀이인데 나는 반대로 sum을 잡고 곱이 되는 수를 sum/N, N으로 찾아가는 관점이였다.

+) 리턴값 answer에 추가하지않고 {N,sum/N}으로 표현해도 된다.
*/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    //brown+yellow 가 되는 곱 모두 찾기
    int sum = brown + yellow;
    int N = sum;
    while (sum > 0)
    {
        if (sum % N == 0)
        {
            if ((sum / N + N) * 2 - 4 == brown)
            {
                answer.push_back(N);
                answer.push_back(sum / N);
                break;
            }
        }
        N--;
    }
    return answer;
}