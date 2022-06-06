/*
주식가격
https://programmers.co.kr/learn/courses/30/lessons/42584

이중for문 쓰면 될 것 같았지만 N^2이라 효율성 낮지 않을까 싶었는데 통과되었다.
스택/큐 영역 문제라서 다시한번 풀어보았다.
*/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for (int i = 0; i < prices.size(); i++)
    {
        int time = 0;
        for (int j = i + 1; j < prices.size(); j++)
        {
            time++;
            if (prices[i] > prices[j])
                break;
        }
        answer.push_back(time);
    }
    return answer;
}

//스택 풀이
/*
* 
* 스택으로 풀어보려다가 생각보다 잘 떠오르지않아서 다른 답안을 확인해보니 스택의 상단값을 벡터의 인덱스로 활용해 문제를 푸는 아이디어를 확인할 수 있었다. 
풀이 참고 : https://ssocoit.tistory.com/15 
다른 사람 풀이 첫 답안 
*/
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> s;
    for (int i = 0; i < prices.size(); i++)
    {
        while (!s.empty())
        {
            if (prices[s.top()] <= prices[i])//가격이 줄지 않은 경우 통과
                break;
            answer[s.top()] = i - s.top();//가격이 줄어든 경우
            s.pop();
        }
        s.push(i);//현재 i값을 스택에 넣음
    }
    while (!s.empty())
    {
        answer[s.top()] = prices.size() - s.top() - 1;//종료 - 당시 시간을 값에 넣어준다.
        s.pop();
    }
    return answer;
}