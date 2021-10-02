/*
3613 Java vs C++ 

���ڿ� ���������� ������ Ǯ����ߴµ� ������ ������ �ƴ� ����� ������������..
9�ۼ�Ʈ���� �ڲ� Ʋ���µ� �������� ���̴� ����ó���� ��κ� �� �� ���� �� ��ƴ�.
���߿� �ٽ� �����غ��ƾ߰ڴ�.
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