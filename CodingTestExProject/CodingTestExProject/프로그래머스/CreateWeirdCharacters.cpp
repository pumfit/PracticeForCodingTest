/*
*�̻��� ���� ����� 
https://school.programmers.co.kr/learn/courses/30/lessons/12930?language=cpp

������ Ǯ�� ��� �����ִµ� ��Ǭ ������ sstream�� �ٽ� Ǯ��ôµ� �� Ʋ�ȴ�.
���ɿ��� ������ �����̿������� ������ ��찡 �־ �Ʒ��� ���� ���̺귯�� ����ϴ� ��쿡�� 4,5,8,9,11 ����� ���ϴ� �� ���Ҵ�.
�ε��� �ΰ��� Ǫ�� ������� �����ϰ� ����ߴ�.
*/
//���� 4,5,8,9,11 ����Ǯ��
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
        string answer = "";
        istringstream ss(s);
        string str;
        vector<string> v;
        while(getline(ss,str,' '))
        {
            for(int i = 0;i<str.size();i++)
                str[i] = i%2==0? toupper(str[i]) : tolower(str[i]);
            v.push_back(str);
        }
        for(int i = 0;i<v.size();i++)
            answer += i==v.size()-1? v[i]:v[i]+" ";
        return answer;
}

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int strIdx = 0; int idx = 0;
    while (strIdx < s.size())
    {
        if (s[strIdx] == ' ')
        {
            idx = 0;
        }
        else
        {
            s[strIdx] = idx % 2 == 0 ? toupper(s[strIdx]) : tolower(s[strIdx]);
            idx++;
        }
        strIdx++;
    }
    return s;
}