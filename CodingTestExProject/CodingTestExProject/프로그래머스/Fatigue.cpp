/*
* 피로도
https://programmers.co.kr/learn/courses/30/lessons/87946

N이 8이하길래 전체탐색도 가능하겠다 생각했고
처음에 BT로 풀어야겠다 생각했다. 뭔가 BT맞지만 return 조건이 따로 없긴해서
dfs내 for문 돌고 최대값을 정답에 넣어주는 방식을 사용하면 된다.

dfs에서 cnt+1하는 부분을 밖으로 빼는 실수를 해서 cnt값이 맞지 않아 조금 걸렸고
dungeons도 매개변수로 넣지않고 따로 빼두는게 좋을 것 같다.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int N = 0;
int answer = -1;
int visited[8] = { 0, };

void dfs(int curHp, int cnt, vector<vector<int>> dungeons)
{
    for (int i = 0; i < N; i++)
    {
        if (curHp < dungeons[i][0])
            continue;
        if (!visited[i])
        {
            visited[i] = 1;
            dfs(curHp - dungeons[i][1], cnt + 1, dungeons);
            visited[i] = 0;
        }
    }
    answer = max(answer, cnt);
    return;
}

int solution(int k, vector<vector<int>> dungeons) {
    N = dungeons.size();
    sort(dungeons.begin(), dungeons.end());
    dfs(k, 0, dungeons);
    return answer;
}