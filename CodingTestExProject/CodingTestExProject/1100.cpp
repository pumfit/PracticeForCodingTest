/*
1100 ÇÏ¾á Ä­

Ä­ Å©±â´Â 8*8
ÇÏ¾ÈÄ­Àº È¦¼ö ÇàÀÏ¶§ Â¦¼ö, Â¦¼ö ÇàÀÏ¶§ È¦¼ö
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int num = 0;

	for (int i = 0; i < 8; i++)
	{
		string s;
		cin >> s;
		if (i % 2 == 0)
		{
			for (int j = 0; j < 8; j += 2)
			{
				if (s.at(j) == 'F')
					num++;
			}
		}
		else
		{
			for (int j = 1; j < 8; j += 2)
			{
				if (s.at(j) == 'F')
					num++;
			}
		}
	}
	cout << num;
}