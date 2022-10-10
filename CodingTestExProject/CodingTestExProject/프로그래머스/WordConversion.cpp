/*
�ܾ� ��ȯ

https://school.programmers.co.kr/learn/courses/30/lessons/43163

���� Ǭ ���� ������ ������ ������ ���� Ǯ����. �׶� BFS�� Ǯ���ٰ� �ű⼱ �ߺ��� ���Ǿ Ƚ���� ��ȯ�ϴµ� ������� ������
�� ���Ŀ� ��Ʈ��ŷ���� Ǯ� ����߾���.

���� Ÿ�� �ܾ words �� ���ԵǾ� �ִ��� �Ǵ��ϰ�
Ž���� �����Ѵ�. �ش� ������ �� ���ڸ� �����ϴ� ���̹Ƿ� �Ѵܾ �ٸ� �� �Ǵ��ϴ� ChangeEnabled �޼ҵ�� ���氡���� üũ���־���.
�׸��� depth�� ���� ��� ��ü �Ǿ������� ��ȯ�ϰ� �� ���� ��������� ��ȯ���ָ� �ȴ�.
*/
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

bool visited[51] = { 0, };

bool ChangeEnabled(string str, string target)
{
    int cnt = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == target[i])
            cnt++;
    }
    return cnt == str.size() - 1 ? true : false;
}

int FindTargetWord(int depth, int strIdx, string target, vector<string>& words)
{
    visited[strIdx] = 1;
    int cnt = 0;
    if (words[strIdx] == target)
    {
        return depth;
    }
    for (int i = 0; i < words.size(); i++)
    {
        if (visited[i])
            continue;
        if (ChangeEnabled(words[strIdx], words[i]))
        {
            visited[i] = 1;
            cnt = FindTargetWord(depth + 1, i, target, words);
            visited[i] = 0;
        }
    }
    return cnt;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    bool isFindTarget = false;
    //Ÿ�� ���� Ȯ��
    for (int i = 0; i < words.size(); i++)
    {
        if (words[i] == target)
        {
            isFindTarget = true;
            break;
        }
    }
    if (!isFindTarget)
        return 0;
    // Ž�� ����
    for (int i = 0; i < words.size(); i++)
    {
        if (ChangeEnabled(words[i], begin))
        {
            answer = FindTargetWord(1, i, target, words);
        }
    }
    return answer;
}