/*
1871 ���� �ڵ��� ��ȣ��

string ���ڿ� �ٷ��
string ���ڿ� ������ Ǯ���� iostream����Ͽ� ����Ǯ��

����
http://www.cplusplus.com/reference/string/string/
+
���� ���� �߸��ؼ� �ѹ� Ʋ�ȴ� ��������

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