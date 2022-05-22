/*
�ĺ�Ű 

������ Ǯ����ٰ� �������� ���� �����˻� ����Ǯ�鼭 �̰͵� ���� �������� �; Ǯ�� ã�ƺ� ����
�Ʒ� ����� ��Ʈ����ũ�� ���� ��� ������ ����� ���� ���ϰ� �ش� ���տ� �´� ��쿡�� �˻��� �̸� Ű�� ���� �ּҼ��� �Ǵ��Ѵ�.
���ϼ��� ��쵵 ��Ʈ����ŷ�� ����� �κ� ������ ������ �� �Ǵ��Ѵ�.
(answer[i] & bit) == answer[i]�̺κ��� �κ� �������� Ȯ���ϴ� �κ� �ε�
��Ʈ a,b �� �ִٸ� a & b �� a�� b�� �������� �ǹ��Ѵ�. �� a & b == a�� b�� a�� ���������� Ȯ���ϴ� ������ �ȴ�.
*/

#include <string>
#include <map>
#include <vector>

using namespace std;

vector<int> answer;

//���ϼ� �Ǵ� �̶� anwer�� ������ ������ ������ ������ 1���� �����Ƿ� �̹� ���ϼ� �Ǵܿ� ����� ��� �κ������� �ȴ�.
bool checkMin(int bit)
{
    for (int i = 0; i < answer.size(); i++)
    {
        if ((answer[i] & bit) == answer[i])//�ּҼ��� �������� ����
            return false;
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    //��Ʈ����ŷ�� ���� ��� ������ ���Ѵ�.
    for (int i = 0; i < 1 << relation[0].size(); i++)
    {
        map<string, int> m; // ���� 
        for (int j = 0; j < relation.size(); j++)
        {
            string s;
            for (int k = 0; k < relation[0].size(); k++)
            {
                // ���� i�� ���ԵǴ� ���̶�� �߰��Ѵ�. 
                if (i & (1 << k))
                    s += relation[j][k];
            }
            m[s] += 1;
        }
        //m.size() == relation.size() ���ϼ� �Ǵ�
        if (m.size() == relation.size() && checkMin(i))
        {
            answer.push_back(i);
        }
    }
    return answer.size();
}