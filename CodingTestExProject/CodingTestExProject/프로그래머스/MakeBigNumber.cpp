/*
ū �� �����
https://programmers.co.kr/learn/courses/30/lessons/42883

idx�� 0���� �ʱ�ȭ�ϰ� Ǯ���ٰ� ���� 3�� ��� ���ذ����� ���� �;��� ����
�����غ��� 19�� ���ο��� idx +1�� ���༭ �⺻ ����ó�� �� ó������ ���õ��� �ʴ� ������ �ƴ�
0�� �ε����� ���õǴ°����� ������ �־���.
�� �ʱ�ȭ ��������

�� ������ ��ü Ž������ �ð��ʰ� �ѹ� �����µ� �������� �� Ž�� ���� �����ϴ°� �´� �������� �����س��Ⱑ �������.
Ž��� ���� �� Ǯ��鼭 ������ �� ���� �� ����.
*/
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int num = number.size() - k;
    int idx = -1;
    for (int i = 0; i < num; i++)
    {
        char max = ' ';
        for (int j = idx + 1; j <= k + i; j++)//Ž�� ����
        {
            char n = number[j];
            if (n > max)
            {
                max = n;
                idx = j;
            }
        }
        answer.push_back(max);
    }
    return answer;
}