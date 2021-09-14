/*
10174 �Ӹ����

ȸ��(����) �Ǵ� �Ӹ����(palindrome)�� �Ųٷ� �о ����� �д� �Ͱ� ���� �����̳� 
����, ����, ���ڿ�(sequence of characters) ���̴�. 
���� ���� ���̿� �ִ� ���⳪ ���� ��ȣ�� �����Ѵ�.

https://ko.wikipedia.org/wiki/%ED%9A%8C%EB%AC%B8

�Ӹ������ ������ ������ �ڷ� ������ �Ȱ��� �ܾ ���ڵ��� ���Ѵ�. 
�Ϲ������� ��ҹ��ڸ� �������� ������, ������ �����Ѵ�.

��� ���ο� ���� �Ӹ�������� �ƴ����� �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

cin.ignore(),getline(cin.s) �ذ� �־��µ� �̹� ��ȸ�� �ٽ� �����ߴ�.
���߿� ��°� �빮�ڷ� �Ἥ �ι�Ʋ�ȴ�..
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int N;
	bool isPalindrome = true;
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++)
	{
		string s;
		getline(cin,s);
		for (int j = 0; j < s.length(); j++)
		{
			s[j] = toupper(s[j]);
		}
		for (int j = 0; j < s.length()/2; j++)
		{
			if (s[j] != s[s.length() - 1 - j])
			{
				isPalindrome = false;
			}
		}
		if (isPalindrome)
		{
			cout << "Yes" <<endl;
		}
		else
		{
			cout << "No" << endl;
		}
		isPalindrome = true;
	}
}