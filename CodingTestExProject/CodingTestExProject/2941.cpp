/*
2941 ũ�ξ�Ƽ�� ���ĺ�

compare �Լ� ��ȯ���� ���� �� 1�̶�� �����ؼ� Ǫ�µ� �� �ɷȴ�.
substr()�Լ��� compare()�Լ� �׸��� �ٸ� string �Լ��鿡 ���� �ڼ��� �˾Ƶ־��� �� ����.

string a = "aaa";
string b = "bbb";

if ( a.compare(b) < 0 )         1) aaa < bbb�� �ǹ�
if ( a.compare(b) == 0 )        2) aaa == bbb�� �ǹ�
if ( a.compare(b) > 0 )         3) aaa > bbb�� �ǹ�

��ó : https://yyman.tistory.com/465
*/
#include<iostream>
#include <string>
using namespace std;

int main()
{
	string alphabet[] = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
	int num = 0;
	string s;
	cin >> s;

	while (s.length() != 0)
	{
		for (int i = 0; i < 8; i++)
		{
			if ((s.substr(0, alphabet[i].length())).compare(alphabet[i]) == 0)
			{
				s.erase(0, alphabet[i].length());
				num++;
				break;
			}
			else if (i == 7)
			{
				s.erase(0, 1);
				num++;
			}
		}
	}
	cout << num;

}