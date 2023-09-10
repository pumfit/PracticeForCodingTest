/*
2941 크로아티아 알파벳

compare 함수 반환값이 같을 때 1이라고 생각해서 푸는데 좀 걸렸다.
substr()함수와 compare()함수 그리고 다른 string 함수들에 대해 자세히 알아둬야할 것 같다.

string a = "aaa";
string b = "bbb";

if ( a.compare(b) < 0 )         1) aaa < bbb를 의미
if ( a.compare(b) == 0 )        2) aaa == bbb를 의미
if ( a.compare(b) > 0 )         3) aaa > bbb를 의미

출처 : https://yyman.tistory.com/465
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