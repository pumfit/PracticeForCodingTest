/*
ü����
https://school.programmers.co.kr/learn/courses/30/lessons/42862#qna

ü������ �Ҿ���� ��� �������� Ȯ���ϰ� ������ Ȯ���ϸ� �ǰڴ� �ؼ� �Ʒ��Ͱ��� ����for�����ȴ�. N �� 30�ۿ� �ȵǾ ����� �Ǵµ� ���� �� ȿ������ ����� ���������� ������ ����ߴ�.
�׸��� ���� ���� ���� � �� Ʋ�ȴµ� ������ ������ �л��� ���� ���� ��츦 ���� �����ص����ʾ� ���� ó���ߴ�.
�� ���Ŀ��� 2���� ��������ʾҴµ� �� ������ �迭�� ���ĵ����ʾƼ� ����...�и� ������ �� ���ĵ� ä�� ���ͼ� �׷� �� �˾Ҵµ� �ƴϿ���.

�߰��� 30ũ���� 2���� �迭�� ����Ǯ�̸� �ұ��߾��µ� �ٸ� Ǯ�� ���� �׷� �ʿ����
�ϳ��� �迭���� ���� ü���� + �Ҿ���� ü���� - �ʱ�ȭ�� ������ ���� ���ϴ� Ǯ�̰� �־���.
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    answer = n - lost.size();
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    for (int i = 0; i < lost.size(); i++)
    {
        //������ ������ �л��� ���� ���� ���
        for (int j = 0; j < reserve.size(); j++)
        {
            if (lost[i] == reserve[j])
            {
                answer++;
                reserve[j] = -1;
                lost[i] = -1;
                break;
            }
        }
    }
    for (int i = 0; i < lost.size(); i++)
    {
        for (int j = 0; j < reserve.size(); j++)
        {
            if (lost[i] - 1 == reserve[j])
            {
                answer++;
                reserve[j] = -1;
                break;
            }
            if (lost[i] + 1 == reserve[j])
            {
                answer++;
                reserve[j] = -1;
                break;
            }
        }
    }
    return answer;
}