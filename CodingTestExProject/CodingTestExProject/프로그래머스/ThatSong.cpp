/*
��� �� ��
2018 KAKAO BLIND RECRUITMENT

�������� �ð� ���� �ɸ� ���� 

1. string�� ��ó���Ѵ�.
2. #�� ���� ��� �빮�ڸ� �ҹ��ڷ� ��ȯ�Ѵ�.
3. �÷��� �ð��� ��� �ݺ��ǹǷ� ����� ���縦 ���Ѵ�.
4. find�� ��� �� ������ Ȯ��
5. ���ǿ� �´� ���� ���� ��� ���̰� �� ������ ��ȯ

���� �ɷȴ� ������ find �Լ��� �����ʰ� ���� �����Ϸ� �ߴ��� �̺κ��� ����� �̷� ���� �ʾҰ�
���� find�Լ� ã�Ƽ� ��ü�ϴ� ��� ���ɴ� ����ߴ�.
�׷��� ���� ������ ������ �� �� �����µ� ������ ������� ������̸� �������� ����Ѵٴ� ������ ���Ծ ���� �ش� �κ��� �����ϴ� ����ߴ�.

���ڿ� Ž�� ���� �˰����� �˰��� �����ð��� ������µ�
����� �� �ȳ��� ������ �ѹ� �ٽ� �����ϴ� ���� ���� �� ����.
*/
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int prevTime = 0;
    vector<pair<int, string>> ans;
    for (int i = 0; i < musicinfos.size(); i++)
    {

        istringstream ss(musicinfos[i]);
        string s;
        vector<string> v;
        while (getline(ss, s, ','))
        {
            v.push_back(s);
        }
        //# ó���ϱ�
        string M = "";
        for (int j = 0; j < m.size(); j++)
        {
            if (m[j] == '#')
            {
                M[M.size() - 1] = tolower(m[j - 1]);
            }
            else
            {
                M.push_back(m[j]);
            }
        }
        //��� �ð� ���ϱ�
        int startTime = stoi(v[0].substr(0, 2)) * 60 + stoi(v[0].substr(3, 2));
        int endTime = stoi(v[1].substr(0, 2)) * 60 + stoi(v[1].substr(3, 2));
        int playTime = endTime - startTime;
        // # ��ȯ
        string lyric = "";
        for (int j = 0; j < v[3].size(); j++)
        {
            if (v[3][j] == '#')
            {
                lyric[lyric.size() - 1] = tolower(v[3][j - 1]);
            }
            else
            {
                lyric.push_back(v[3][j]);
            }
        }
        string playStr = "";
        for (int j = 0; j < playTime; j++)
        {
            playStr += lyric[j % lyric.size()];
        }

        if (playStr.find(M) != string::npos)
        {
            if (playTime > prevTime)
            {
                answer = v[2];
                prevTime = playTime;
            }
        }

    }
    return answer;
}