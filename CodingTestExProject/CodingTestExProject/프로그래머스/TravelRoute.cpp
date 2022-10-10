/*
여행 경로
https://school.programmers.co.kr/learn/courses/30/lessons/43164

단어 변환하고 유사한 문제

어떻게 경로를 가지고 비교할 것인가?

여러 가지 답이 나오는 경우 알파벳 순으로 반환해야하는데
이는 여러 경로를 구한뒤 비교하는 것이 아니라 처음에 티켓 정렬을 통해 정리해두면 처음 구한 경로가 알파벳 순으로 가장 빠른 경로가 된다.

제출후 테케 1,2 번에서 틀렸었는데 답이 나오지 않는 경우에
초반에 추가해두었던 ICN가 남아있어서 였다. 마지막에 pop_back으로 해당값을 빼주면 테케 1,2번도 모두 통과한다.

어떻게 여러개의 답을 처리해야하나로 고민하다 도저히 모르겠어서 찾아봤는데 생각보다 간단했고
아직도 bt 값 반환 순서가 헷갈리는 것 같아서 N과 M 문제들 복습해야할 것 같다.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool visited[5001] = { 0, };

bool FindPath(int depth, string city, vector<string>& v, vector<vector<string>>& tickets)
{
    v.push_back(city);

    if (depth == tickets.size())
    {
        return true;
    }

    for (int i = 0; i < tickets.size(); i++)
    {
        if (visited[i])
            continue;
        if (city == tickets[i][0])
        {
            visited[i] = 1;
            bool isClear = FindPath(depth + 1, tickets[i][1], v, tickets);
            if (isClear)
                return true;
            visited[i] = 0;
        }
    }
    v.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end());
    FindPath(0, "ICN", answer, tickets);
    return answer;

}