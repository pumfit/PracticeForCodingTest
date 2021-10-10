/*
2010 플러그
마지막 멀티탭을 제외한 멀티탭들은 플러그를 하나 제외해야한다.
*/
#include<iostream>
using namespace std;

int main() 
{
	int n,m;
	int answer = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> m;
		answer += m;
		if (i != n - 1)
		{
			answer -= 1;
		}
	}

	cout << answer;

}
