/*
메뉴 리뉴얼
https://programmers.co.kr/learn/courses/30/lessons/72411

문제에 제시된대로 풀어나가면 되는 문제
먼저 코스 수 만큼 진행하도록 하고
각 메뉴안에서 조합을 모두 구한다. 중복되는 메뉴의 경우 map을 사용하여 계산을 진행하였고
가장 많이 등장한 경우를 최대값으로 해당 수만큼 있는 메뉴들만 정답에 넣도록 진행하였다.
오름차순으로 정렬하는 조건 놓쳐서 이상하다 싶었는데 생각보단 쉽게 풀었다.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    //오름차순 정렬
    for (int j = 0; j < orders.size(); j++)
        sort(orders[j].begin(), orders[j].end());
    for (int i = 0; i < course.size(); i++)
    {
        map<string, int> recommend;
        for (int j = 0; j < orders.size(); j++)
        {
            //course수보다 주문 수가 적으면 패스
            if (orders[j].size() < course[i])
                continue;
            vector<int> v;
            //조합 구하기
            for (int k = 0; k < course[i]; k++)
                v.push_back(1);
            for (int k = 0; k < orders[j].size() - course[i]; k++)
                v.push_back(0);
            sort(v.begin(), v.end());

            do {
                string s = "";
                for (int k = 0; k < orders[j].size(); k++)
                {
                    if (v[k] == 1)
                        s += orders[j][k];
                }
                if (recommend.find(s) == recommend.end())
                    recommend.insert({ s,1 });
                else
                    recommend[s]++;
            } while (next_permutation(v.begin(), v.end()));
        }
        int max = 0;
        for (auto m : recommend)
        {
            if (m.second > max)
                max = m.second;
        }
        if (max < 2)//추천 메뉴가 2번이상 등장한 경우에만 추가한다.
            continue;
        for (auto m : recommend)
        {
            if (m.second == max)
                answer.push_back(m.first);
        }

    }
    sort(answer.begin(), answer.end());
    return answer;
}