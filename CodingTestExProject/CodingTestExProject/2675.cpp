/*
2675 ���ڿ� �ݺ�

���ڿ� S�� �Է¹��� �Ŀ�, �� ���ڸ� R�� �ݺ��� �� ���ڿ� P�� ���� �� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

���ڿ��� �޾ƿ��� �ݺ�Ƚ����ŭ �ݺ����� ������ָ� Ǯ �� �ִ� �����̴�.
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int N;
		string s;
		string ans = "";
		cin >> N >> s;
		for (int j = 0; j < s.length(); j++)
		{
			for (int k = 0; k < N; k++)
			{
				ans += s[j];
			}
		}
		cout << ans << endl;
	}
}