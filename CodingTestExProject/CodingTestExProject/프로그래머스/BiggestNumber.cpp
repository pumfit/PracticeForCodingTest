/*
���� ū ��

https://programmers.co.kr/learn/courses/30/lessons/42746

�̹����� �̹��� ó�� Ǭ���� �ƴϰ� �������� �߾��µ� 3�� ���ɰ� �ʹ� ���ذ� ���� �ʾҴ�.

�� �̹��� ���ɸ� ���ظ� ���ؼ� ����������.

������ �ᱣ�� "353333323021000"��(��) ��� "353233333021000"��(��) �ٸ��ϴ�.
�ƴ� 353333323021000�� 353233333021000���� ū�� ���� �ʳ�..? �̹��� ���� ū �� ã�°� �ƴϿ���??�����ϰ� �Ѱ�µ�
���̾��Ե� ���ɰ� Ʋ���� ����� �� �ִ� ��������.

������ �ϴ� ����� string���� �ΰ��� ������ �� �� ū ���� ��ȯ�ϸ� �ǰ� �� ��� 00�̰ų� 000���� ���ԵǾ� ���� �� �� �����Ƿ�
�� ���ڸ��� 0�� ���� 0�� ��ȯ���ָ� �Ǵ� �����̴�.
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string& A, string& B)
{
    return A + B > B + A;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for (int i = 0; i < numbers.size(); i++)
        v.push_back(to_string(numbers[i]));
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < numbers.size(); i++)
        answer += v[i];
    if (answer[0] == '0')
        return "0";
    return answer;
}