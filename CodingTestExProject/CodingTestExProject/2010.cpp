/*
2010 �÷���
������ ��Ƽ���� ������ ��Ƽ�ǵ��� �÷��׸� �ϳ� �����ؾ��Ѵ�.
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
