/*
2021 KAKAO BLIND RECRUITMENT
���� �˻�

ù��° Ǯ�̴� ȿ���� 0 �� ���� Ǯ��
for�� �ι������� ���� -> ���� ������ ���� �迭�� �ְ� �´� �� Ȯ���ϴ� ������� Ǯ����.

�ش� Ǯ��
https://tech.kakao.com/2021/01/25/2021-kakao-recruitment-round-1/

���� �ذ��� ���ؼ�, �����ڵ��� �׷캰�� �����ϰ� �̸� �з��صθ� �� ���� ���Ǹ��� �����ڵ��� INFO �迭���� ã�� �ʾƵ� �˴ϴ�.

��Ʈ����ŷ/�̺�Ž�� �Ἥ Ǫ�� Ǯ��
���� �������� �κ��� ��ü ������ ���� �κ��� �������� �ʾҴٰ� �����ϴµ� �� �ɷȾ��� 
��ó�� Ǯ� ȿ�������� �ϳ��� ����� ���ؼ� �ǰ� ��Ȳ���������µ�
������ �Ǵ� �κ��� �̺�Ž�� ������ sort�� �����ϴ� �κ��̿���. �̺κ��� 156��°�� ���ΰ� ���� �ٲ��ִ� ȿ���� �׽�Ʈ�� ����ϰԵǾ���.

2�ܰ� ���� �߿����� ��û ����� ���� �� ������ �ڷᱸ���� ���� ���� + ���� �� �̺�Ž�� (ȿ����) + ���ڿ� �Ľ� ��� �Ű����ϴ� �κ��� ���Ƽ�
��Ʈ����ŷ �Ⱦ��� ��Ʈ��ŷ���ε� ���Ŀ� Ǯ��� ���� �� ����.

���� ���� Ǯ��
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
        //���� ��ü�� ���鼭 ���տ� �־��ش�.
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
                // ���� i�� ���ԵǴ� ���̶�� �߰��Ѵ�. 
                if (i & (1 << k))
                    subInfo += info[k];
                else
                    subInfo += "-";
            }
            // ���յ� ������ Ű���� �ȴ�.
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