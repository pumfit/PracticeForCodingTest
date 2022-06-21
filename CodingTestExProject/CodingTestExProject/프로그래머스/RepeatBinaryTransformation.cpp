/*
* ���� ��ȯ �ݺ��ϱ�
* ���� �ڵ� ç���� ����1
https://programmers.co.kr/learn/courses/30/lessons/70129

�������� ������ �״�� �����ϸ� �Ǵ� ���� 

�ٸ� Ǯ�� ���ٺ��� �ݺ������� ������ ����� ����� Ư���ߴ�.
        for(int i=length; i>0; i=i/2){
            s.push_back(i%2+'0');
        }
2������ ���ϴ� ����� 2�� ���� �������� ���ϴ� ����̴ٺ��� ���� ���̵� ǥ�� �����ϴٴ� ���� �˾Ҵ�.
0 + '0' �� 00�� �ƴ� 0���� 
*/
#include <string>
#include <vector>

using namespace std;

string toBinary(int s)
{
    string r;
    while (s != 0) {
        r += (s % 2 == 0 ? "0" : "1");
        s /= 2;
    }
    return r;
}

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0;
    int idx = 0;
    while (s != "1")
    {
        idx++;
        int len = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
                len++;
            else
                cnt++;
        }
        s = toBinary(len);
    }
    answer.push_back(idx);
    answer.push_back(cnt);
    return answer;
}