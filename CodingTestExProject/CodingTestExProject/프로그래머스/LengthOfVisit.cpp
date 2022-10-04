/*
방문 길이

https://school.programmers.co.kr/learn/courses/30/lessons/49994

set으로 중복없이 지나온 길을 넣는 문제

첫 풀이에 8번 테케부터 쫙 틀렸는데 반례찾는게 어려웠다. A-B이동시 B-A도 지난간 것으로 체크해야하하기 때문에
공개된 테케 말고 8번이후로 틀리는 것이였고 이때문에 길을 추가할때 cur next와 next cur 두개 모두 추가하고 답을 2로 나눈 방식으로 변경했다.

+) 구조체
구조체로 쓸까하다가 pair가 더 깔끔한 것 같아서 pair를 사용 
*/
#include <string>
#include <set>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    set<pair<pair<int, int>, pair<int, int>>> s;
    pair<int, int> curPos = { 0,0 };
    pair<int, int> nextPos = { 0,0 };
    for (int i = 0; i < dirs.size(); i++)
    {
        if (dirs[i] == 'U')
        {
            if (curPos.second + 1 > 5)
                continue;
            nextPos = { curPos.first,curPos.second + 1 };
        }
        else if (dirs[i] == 'D')
        {
            if (curPos.second - 1 < -5)
                continue;
            nextPos = { curPos.first,curPos.second - 1 };
        }
        else if (dirs[i] == 'R')
        {
            if (curPos.first + 1 > 5)
                continue;
            nextPos = { curPos.first + 1,curPos.second };
        }
        else if (dirs[i] == 'L')
        {
            if (curPos.first - 1 < -5)
                continue;
            nextPos = { curPos.first - 1,curPos.second };
        }
        s.insert({ curPos,nextPos });
        s.insert({ nextPos,curPos });
        curPos = nextPos;

    }
    return s.size() / 2;
}