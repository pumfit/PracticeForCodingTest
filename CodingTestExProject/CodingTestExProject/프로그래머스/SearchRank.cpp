/*
2021 KAKAO BLIND RECRUITMENT
순위 검색

첫번째 풀이는 효율성 0 점 맞은 풀이
for문 두번돌려서 쿼리 -> 인포 순으로 각각 배열에 넣고 맞는 지 확인하는 방식으로 풀었다.

해답 풀이
https://tech.kakao.com/2021/01/25/2021-kakao-recruitment-round-1/

문제 해결을 위해서, 지원자들을 그룹별로 적절하게 미리 분류해두면 매 문의 조건마다 지원자들을 INFO 배열에서 찾지 않아도 됩니다.

비트마스킹/이분탐색 써서 푸는 풀이
가장 문제였던 부분은 전체 조건이 없는 부분을 포함하지 않았다가 수정하는데 꽤 걸렸었고 
이처럼 풀어도 효율성에서 하나도 통과를 못해서 되게 당황스러웠었는데
문제가 되는 부분은 이분탐색 이전에 sort를 진행하는 부분이였다. 이부분을 156번째쯤 라인과 같이 바꿔주니 효율성 테스트를 통과하게되었다.

2단계 문제 중에서도 엄청 어려운 쪽인 것 같은데 자료구조에 대한 이해 + 정렬 후 이분탐색 (효율성) + 문자열 파싱 등등 신경써야하는 부분이 많아서
비트마스킹 안쓰고 백트래킹으로도 이후에 풀어보면 좋을 것 같다.

도움 받은 풀이
https://wadekang.tistory.com/15
*/
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for (int i = 0; i < query.size(); i++)
    {
        istringstream ss(query[i]);
        string s;
        string arr[5]; int idx = 0;
        while (getline(ss, s, ' '))
        {
            if (s == "and")
                continue;
            else {
                arr[idx] = s;
                idx++;
            }
        }
        int minScore = stoi(arr[4]);
        int cnt = 0;
        for (int j = 0; j < info.size(); j++)
        {
            istringstream ss(info[j]);
            string s;
            string info[5]; int idx = 0;
            while (getline(ss, s, ' '))
            {
                info[idx] = s;
                idx++;
            }
            if (minScore > stoi(info[4]))
                continue;
            if ((info[0] != arr[0]) && (arr[0] != "-"))
                continue;
            if ((info[1] != arr[1]) && (arr[1] != "-"))
                continue;
            if ((info[2] != arr[2]) && (arr[2] != "-"))
                continue;
            if ((info[3] != arr[3]) && (arr[3] != "-"))
                continue;
            cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}

#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> GetKey(string& s)
{
    vector<string> key;
    string word = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            if (word != "and")
                key.push_back(word);
            word = "";
        }
        else
        {
            word += s[i];
        }
    }
    key.push_back(word);
    return key;
}

#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> GetKey(string& s)
{
    vector<string> key;
    string word = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            if (word != "and")
                key.push_back(word);
            word = "";
        }
        else
        {
            word += s[i];
        }
    }
    key.push_back(word);
    return key;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    unordered_map<string, vector<int>> m;
    for (int i = 0; i < (1 << 4); i++)
    {
        //쿼리 전체를 돌면서 조합에 넣어준다.
        for (int j = 0; j < info.size(); j++)
        {
            string subInfo = "";
            istringstream ss(info[j]);
            string s;
            string info[5]; int idx = 0;
            while (getline(ss, s, ' '))
            {
                info[idx] = s;
                idx++;
            }
            for (int k = 0; k < 4; k++)
            {
                // 조합 i에 포함되는 행이라면 추가한다. 
                if (i & (1 << k))
                    subInfo += info[k];
                else
                    subInfo += "-";
            }
            // 조합된 조건이 키값이 된다.
            m[subInfo].push_back(stoi(info[4]));
        }
    }
    for (auto& iter : m)
    {
        sort(iter.second.begin(), iter.second.end());
    }

    for (int i = 0; i < query.size(); i++)
    {
        vector<string> k = GetKey(query[i]);
        string key = k[0] + k[1] + k[2] + k[3];
        vector<int> v = m[key];
        int cnt = v.end() - lower_bound(v.begin(), v.end(), stoi(k[4]));
        answer.push_back(cnt);
    }

    return answer;
}