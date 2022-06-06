
/*
* 영어 끝말잇기
* Summer/Winter Coding(~2018)

https://programmers.co.kr/learn/courses/30/lessons/12981

1. 같은 단어를 쓰는 경우 탈락
2. 마지막 문자와 첫 문자가 다른 경우
같은 단어의 경우 map으로 관리했고 문자는 다르지않은 경우 prev값을 바꿔주는 방식으로 진행했다.
확실히 같은 수준 문제라도 예전 문제들이 더 쉬운 느낌
*/
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, int> m;
    m.insert({ words[0],1 });
    char prevChar = words[0][words[0].size() - 1];
    for (int i = 1; i < words.size(); i++)
    {
        if (words[i][0] != prevChar)//마지막 문자와 첫 문자가 다른 경우
        {
            answer.push_back((i + 1) % n == 0 ? n : (i + 1) % n);//번호
            answer.push_back(i / n + 1);//차례
            return answer;
        }
        else
        {
            prevChar = words[i][words[i].size() - 1];
        }
        if (m.find(words[i]) != m.end())//같은 단어 쓰는 경우
        {
            answer.push_back((i + 1) % n == 0 ? n : (i + 1) % n);
            answer.push_back(i / n + 1);
            return answer;
        }
        m.insert({ words[i],1 });
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}