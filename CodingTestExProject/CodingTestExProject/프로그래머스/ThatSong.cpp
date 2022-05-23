/*
방금 그 곡
2018 KAKAO BLIND RECRUITMENT

생각보다 시간 많이 걸린 문제 

1. string을 전처리한다.
2. #이 들어가는 경우 대문자를 소문자로 변환한다.
3. 플레이 시간이 길면 반복되므로 재생된 가사를 구한다.
4. find로 방금 그 곡인지 확인
5. 조건에 맞는 곡중 가장 재생 길이가 긴 제목을 반환

오래 걸렸던 이유는 find 함수를 쓰지않고 직접 구현하려 했더니 이부분이 제대로 이뤄 지지 않았고
이후 find함수 찾아서 대체하니 몇몇 테케는 통과했다.
그러고 나서 왜인지 이유을 알 수 없었는데 동일한 결과에는 재생길이를 기준으로 출력한다는 조건을 빼먹어서 였고 해당 부분을 수정하니 통과했다.

문자열 탐색 관련 알고리즘은 알고리즘 수업시간에 배웠었는데
기억이 잘 안나서 다음에 한번 다시 정리하는 것이 좋을 것 같다.
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
        //# 처리하기
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
        //재생 시간 구하기
        int startTime = stoi(v[0].substr(0, 2)) * 60 + stoi(v[0].substr(3, 2));
        int endTime = stoi(v[1].substr(0, 2)) * 60 + stoi(v[1].substr(3, 2));
        int playTime = endTime - startTime;
        // # 변환
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