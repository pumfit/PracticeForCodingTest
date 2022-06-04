/*
�޴� ������
https://programmers.co.kr/learn/courses/30/lessons/72411

������ ���õȴ�� Ǯ����� �Ǵ� ����
���� �ڽ� �� ��ŭ �����ϵ��� �ϰ�
�� �޴��ȿ��� ������ ��� ���Ѵ�. �ߺ��Ǵ� �޴��� ��� map�� ����Ͽ� ����� �����Ͽ���
���� ���� ������ ��츦 �ִ밪���� �ش� ����ŭ �ִ� �޴��鸸 ���信 �ֵ��� �����Ͽ���.
������������ �����ϴ� ���� ���ļ� �̻��ϴ� �;��µ� �������� ���� Ǯ����.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    //�������� ����
    for (int j = 0; j < orders.size(); j++)
        sort(orders[j].begin(), orders[j].end());
    for (int i = 0; i < course.size(); i++)
    {
        map<string, int> recommend;
        for (int j = 0; j < orders.size(); j++)
        {
            //course������ �ֹ� ���� ������ �н�
            if (orders[j].size() < course[i])
                continue;
            vector<int> v;
            //���� ���ϱ�
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
        if (max < 2)//��õ �޴��� 2���̻� ������ ��쿡�� �߰��Ѵ�.
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