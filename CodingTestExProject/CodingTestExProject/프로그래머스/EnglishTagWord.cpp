
/*
* ���� �����ձ�
* Summer/Winter Coding(~2018)

https://programmers.co.kr/learn/courses/30/lessons/12981

1. ���� �ܾ ���� ��� Ż��
2. ������ ���ڿ� ù ���ڰ� �ٸ� ���
���� �ܾ��� ��� map���� �����߰� ���ڴ� �ٸ������� ��� prev���� �ٲ��ִ� ������� �����ߴ�.
Ȯ���� ���� ���� ������ ���� �������� �� ���� ����
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
        if (words[i][0] != prevChar)//������ ���ڿ� ù ���ڰ� �ٸ� ���
        {
            answer.push_back((i + 1) % n == 0 ? n : (i + 1) % n);//��ȣ
            answer.push_back(i / n + 1);//����
            return answer;
        }
        else
        {
            prevChar = words[i][words[i].size() - 1];
        }
        if (m.find(words[i]) != m.end())//���� �ܾ� ���� ���
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