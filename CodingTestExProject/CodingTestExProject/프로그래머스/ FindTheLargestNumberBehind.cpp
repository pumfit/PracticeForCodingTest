/*
뒤에 있는 큰 수 찾기

처음에 N^2로 풀고 시간초과나서 이분탐색문제인가 했는데
스택을 이용해서 푸는 문제였다. 인덱스만을 stack에 쌓아가 해당되는 인덱스의 뒤에 있는 큰 수를 구할 수가 있다.

*/
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());

    // 정답을 모두 -1로 초기화
    for(int i = 0;i<answer.size();i++)
        answer[i] = -1;

    stack<int> s;
    // numbers 만큼 반복
    for(int i = 0;i<answer.size();i++)
    {
        // 스택이 빌때까지 반복
        while(!s.empty())
        {
            // 현재 스택의 가장 위 인덱스의 값이 현재 값 보다 크거나 같다면 반복을 중단한다.
            if(numbers[s.top()]>=numbers[i])
            {
                break;
            }
            // 위 경우가 아니라면
            // index s.top() 에 대한 '뒤에 있는 큰 수'이 된다.
            answer[s.top()] = numbers[i];
            s.pop();
            
        }
        // 해당되는 인덱스를 넣어준다.
        s.push(i);
        
    }
    return answer;
}