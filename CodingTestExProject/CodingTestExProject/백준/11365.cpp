/*
11365 !�к� ����

���� ���� ���� �ް� �ϴ� �Լ��� string�� getline ��������!
���� : https://m.blog.naver.com/mms0801/221864387707

*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	while (true)
	{
		getline(cin, s);
		if (s == "END")
			return 0;
		for (int i = s.size() - 1; i >= 0; i--)
			cout << s[i];
		cout << endl;
	}
	return 0;
}