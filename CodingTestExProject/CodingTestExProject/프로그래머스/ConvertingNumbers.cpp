/*
숫자 변환하기

https://school.programmers.co.kr/learn/courses/30/lessons/154538

문제를 단순히 보면 사용 가능한 연산을 하다가 y을 넘으면 멈추면 될 것 같다. 하지만 곱셈과 덧셈으로만 이뤄져있고 x,y,n이 정수이다 보니
반대로 y에서 x를 찾아가는 식으로 풀이를 진행했다.
queue를 사용해서 경우의 수를 구해가고 횟수는 pair를 통해 push를 진행할때마다 값을 증가하도록 했다.

이후에 dp로 풀어보기
*/

#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int x, int y, int n) {
    int answer = 0;
    queue<pair<int,int>> q;
    q.push({y,0});
    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();
        if(cur.first==x)
        {
            return cur.second;
        }
        for(int i = 0;i<3;i++)
        {
            if(i==0)
            {
                if(cur.first%2==0)
                    q.push({cur.first/2,cur.second+1});
            }else if(i==1)
            {
                if(cur.first%3==0)
                    q.push({cur.first/3,cur.second+1});
            }else{
                if(cur.first-n>=x)
                    q.push({cur.first-n,cur.second+1});
            }
        }
    }
    return -1;
}