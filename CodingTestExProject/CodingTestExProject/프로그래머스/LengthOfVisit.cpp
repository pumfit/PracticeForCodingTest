/*
�湮 ����

https://school.programmers.co.kr/learn/courses/30/lessons/49994

set���� �ߺ����� ������ ���� �ִ� ����

ù Ǯ�̿� 8�� ���ɺ��� �� Ʋ�ȴµ� �ݷ�ã�°� �������. A-B�̵��� B-A�� ������ ������ üũ�ؾ����ϱ� ������
������ ���� ���� 8�����ķ� Ʋ���� ���̿��� �̶����� ���� �߰��Ҷ� cur next�� next cur �ΰ� ��� �߰��ϰ� ���� 2�� ���� ������� �����ߴ�.

+) ����ü
����ü�� �����ϴٰ� pair�� �� ����� �� ���Ƽ� pair�� ��� 
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