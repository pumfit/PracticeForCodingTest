/*
2902 KMP�� �� KMP�ϱ�?

���ڿ��� �޾ƿ� �������� ��ġ�� �ľ��ϰ� �빮�ڸ� ����ϴ� ����
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s = "", a = "";
	cin >> s;
	a.push_back(s[0]);
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] - '-' == 0)
		{
			a.push_back(s[i + 1]);
		}
	}
	cout << a;
	return 0;
}