/*
2021 KAKAO BLIND RECRUITMENT
���� �˻�

�Ʒ��� ȿ���� 0 �� ���� Ǯ��
for�� �ι������� ���� -> ���� ������ ���� �迭�� �ְ� �´� �� Ȯ���ϴ� ������� Ǯ����.

�ش� Ǯ��
https://tech.kakao.com/2021/01/25/2021-kakao-recruitment-round-1/

���� �ذ��� ���ؼ�, �����ڵ��� �׷캰�� �����ϰ� �̸� �з��صθ� �� ���� ���Ǹ��� �����ڵ��� INFO �迭���� ã�� �ʾƵ� �˴ϴ�.

�ؽ� �����̰� �ؽ� ���� ���� Ǯ�� ������ ��� �Ʒ��� �����ϵ��� �ߴ�.
�ؽ� ���� ����
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