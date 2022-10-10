/*
단어 변환

https://school.programmers.co.kr/learn/courses/30/lessons/43163

어제 푼 코테 문제와 유사한 문제라서 빨리 풀었다. 그때 BFS로 풀려다가 거기선 중복이 허용되어서 횟수를 반환하는데 어려움을 느끼고
그 이후에 백트래킹으로 풀어서 통과했었다.

먼저 타겟 단어가 words 에 포함되어 있는지 판단하고
탐색을 시작한다. 해당 문제는 한 글자를 변경하는 것이므로 한단어만 다른 지 판단하는 ChangeEnabled 메소드로 변경가능을 체크해주었다.
그리고 depth를 통해 몇번 교체 되었는지를 반환하고 이 값을 결과값으로 반환해주면 된다.
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
    //타겟 유무 확인
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
    // 탐색 시작
    for (int i = 0; i < words.size(); i++)
    {
        if (ChangeEnabled(words[i], begin))
        {
            answer = FindTargetWord(1, i, target, words);
        }
    }
    return answer;
}