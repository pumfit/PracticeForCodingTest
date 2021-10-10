/*
3613 Java vs C++ 

문자열 연습용으로 가볍게 풀어보려했는데 가벼운 문제가 아닌 어려운 구현문제였다..
9퍼센트에서 자꾸 틀리는데 질문에서 보이는 예외처리는 대부분 한 것 같아 더 어렵다.
나중에 다시 도전해보아야겠다.
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int i = s.find("_");
	if (i != -1)//c->java long_and_mnemonic_identifier longAndMnemonicIdentifier
	{
		if (s.find("c") == 0)
			s.replace(0, 1, "java");
		if (s[s.size() - 1] == '_'|| s[0] == '_')
		{
			cout << "Error!";
			return 0;
		}
		for (int i = 0; i < s.size(); i++)
		{
			if ('A' <= s[i] && s[i] <= 'Z')
			{
				cout << "Error!";
				return 0;
			}
		}
		while (i != -1)
		{
			i = s.find("_");
			if (i != -1)
			{
				if (i + 1 <= s.size() - 1)
				{
					if (s[i + 1] == '_')
					{
						cout << "Error!";
						return 0;
					}
				}
				s.erase(i, 1);
				if (s.find("_") == -1)
					break;
				if(s[i] != '_')
					s[i] = s[i] - 32;
			}
		}
	}
	else//java->c
	{
		if (s.find("java") == 0)
			s.replace(0, 4, "c");
		if ('A' <= s[0] && s[0] <= 'Z')
		{
			cout << "Error!";
			return 0;
		}
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i]<'A' || s[i]>'z')
			{
				s = "Error!";
				break;
			}
			else if ('A' <= s[i] && s[i] <= 'Z')
			{
				s[i] = s[i] + 32;
				s.insert(i, "_");
			}
		}
	}

	cout << s;
	return 0;
}