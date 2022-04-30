/*
2021 KAKAO BLIND RECRUITMENT
순위 검색

아래는 효율성 0 점 맞은 풀이
for문 두번돌려서 쿼리 -> 인포 순으로 각각 배열에 넣고 맞는 지 확인하는 방식으로 풀었다.

해답 풀이
https://tech.kakao.com/2021/01/25/2021-kakao-recruitment-round-1/

문제 해결을 위해서, 지원자들을 그룹별로 적절하게 미리 분류해두면 매 문의 조건마다 지원자들을 INFO 배열에서 찾지 않아도 됩니다.

해시 문제이고 해시 관련 문제 풀이 경험이 없어서 아래에 정리하도록 했다.
해시 관련 정리
https://www.notion.so/40ee588cf2684acbb5060992e85b092a
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