/*
����Ʈ
https://school.programmers.co.kr/learn/courses/30/lessons/42885

ó���� �����ϰ� ���� ������ ������� �־��µ� �翬�� Ʋ�ȴ�.
�� ���� ���̽��� 10 90 20 80 30 70 40 60 50 50���� ã�� �� �ִµ� ���� ������ �ϸ� 6���� �ʿ��ѵ� ���°� ä��� 5�����ȴ�.
���� �ִ��� limit���� ���ߴ°� �̹����� �ٽ��̴�.

���� ū �� �ϳ��� �����ϰ� ���� �ڸ��� ���� ���� ä��� ������� �����ߴ�.
���� for������ i�� ū���� �����ϰ� 
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int N = 0; int idx = 0;
    // ū ���� �ϳ� ����
    for (int i = people.size() - 1; i >= 0; i--)
    {
        N = people[i];
        //���� ���� ���� �� ���������� ����
        for (int j = idx; j < people.size(); j++)
        {
            if (N + people[j] <= limit)
            {
                N += people[j];
                continue;
            }
            else//limit �Ѿ�� �� �ϳ� �߰�
            {
                idx = j;
                answer++;
                break;
            }
        }
        if (idx >= i)//���� ���� ū ���� ũ�ν��Ǹ� ����
            break;
    }

    return answer;
}