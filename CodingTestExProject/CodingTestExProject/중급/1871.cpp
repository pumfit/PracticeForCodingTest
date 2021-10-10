/*
1871 좋은 자동차 번호판

string 문자열 다루기
string 문자열 문제를 풀때는 iostream사용하여 문제풀이

참조
http://www.cplusplus.com/reference/string/string/
+
범위 설정 잘못해서 한번 틀렸다 조심하자

*/

#include<iostream>
#include <string>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		int sum = 0;
		cin >> s;

		sum = ((s.at(0) - 'A') * 26 * 26) + ((s.at(1) - 'A') * 26) + (s.at(2) - 'A');
		s = s.substr(4, 8);
		int k = stoi(s);
		sum = sum - k > 0 ? sum - k : -sum + k;
		if (sum <= 100)
		{
			cout << "nice" << endl;
		}
		else
		{
			cout << "not nice" << endl;
		}

	}
}