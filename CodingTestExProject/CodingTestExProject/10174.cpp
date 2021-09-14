/*
10174 팰린드롬

회문(回文) 또는 팰린드롬(palindrome)은 거꾸로 읽어도 제대로 읽는 것과 같은 문장이나 
낱말, 숫자, 문자열(sequence of characters) 등이다. 
보통 낱말 사이에 있는 띄어쓰기나 문장 부호는 무시한다.

https://ko.wikipedia.org/wiki/%ED%9A%8C%EB%AC%B8

팰린드롬은 앞으로 읽으나 뒤로 읽으나 똑같은 단어나 숫자들을 말한다. 
일반적으로 대소문자를 구분하지 않지만, 공백은 구분한다.

모든 라인에 대해 팰린드롬인지 아닌지를 구분하는 프로그램을 작성하시오.

cin.ignore(),getline(cin.s) 잊고 있었는데 이번 기회에 다시 복습했다.
와중에 출력값 대문자로 써서 두번틀렸다..
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