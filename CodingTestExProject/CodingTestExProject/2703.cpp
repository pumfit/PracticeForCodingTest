/*
2703 Cryptoquote
Cryptoquote�� � �޽����� ���� ��, �� ���ĺ��� �ٸ� ���ĺ����� ��ȯ�� ��ȣȭ �ϴ� �������
���� ���, HPC PJVYMIY�� �޽����� ���� ��, �̸� ���� �޽����� �ٲ۴ٸ� ACM CONTEST�� �ȴ�.
���������� ��ȣ���� �ص��� ���� ��Ģ�� �־�����.

���� ��� �Է¹ޱ� getlin() �Լ��� ���� ���� Ǯ�̽� ����߾��µ�
�̹� ����Ǯ�̽ÿ� ������ �޾ƿ� T�� ������ ���� ������ �־� cin.ignore()�Լ��� ����ϰ� �Ǿ���.
getline�Լ��� cin.ignore()�� ���� ���� ��ȣȭ�� ���ڿ��� �޾ƿ� �� �־���.
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
		string s;
		string alphabet;
		string ans ="";

		cin.ignore();
		getline(cin, s);
		
		cin >> alphabet;

		for (int j = 0; j < s.length(); j++)
		{		
			if (0 <= s[j] - 'A' && s[j] - 'A' <= 25)
			{
				ans += alphabet[s[j] - 'A'];
			}
			else
			{
				ans += " ";
			}
				
		}
		cout << ans<<endl;

	}

}