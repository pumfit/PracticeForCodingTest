/*
��ü ���� ���
https://programmers.co.kr/learn/courses/30/lessons/1835

��ü ������ ���� �� �ش� ���ǿ� �´� �� �˻��� answer���� üũ�ϸ� �Ǵ� �����̴�.

������ next_permutaition�Լ��� ����Ͽ���.
�Ÿ��� ���̴� ������ ���� �� �����Ͽ��µ� �� ����� �Ÿ��� 0�� ��� �� �ε��� �����δ� 1���̰� ���� �߰������� -1�� ���־�� �Ѵ�.

*/
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
int solution(int n, vector<string> data) {
    string s = "ACFJMNRT";
    sort(s.begin(), s.end());
    int answer = 0;
    do {
        int OIdx = 0; int TIdx = 0;
        //data ������ŭ
        for (int i = 0; i < n; i++)
        {
            //�ε��� ã��
            for (int j = 0; j < s.size(); j++)
            {
                if (s[j] == data[i][0])
                    OIdx = j;
                else if (s[j] == data[i][2])
                    TIdx = j;
            }
            int num = data[i][4] - '0';
            if (data[i][3] == '=')
            {
                if (abs(OIdx - TIdx) - 1 != num)
                    break;
            }
            else if (data[i][3] == '>')
            {
                if (abs(OIdx - TIdx) - 1 <= num)
                    break;
            }
            else {
                if (abs(OIdx - TIdx) - 1 >= num)
                    break;
            }
            if (i == n - 1)
                answer++;

        }
    } while (next_permutation(s.begin(), s.end()));
    return answer;
}