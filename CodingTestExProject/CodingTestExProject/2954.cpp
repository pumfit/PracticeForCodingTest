/*
2954 창영이의 일기장

창영이가 일기장에 작성한 문장을 원래 문장으로 바꾸어 출력하는 문제.

일기는 모음('a','e','i','o','u')의 다음에 'p'를 하나 쓰고, 그 모음을 하나 더 쓴다.
예를 들어, "kemija" 는 "kepemipijapa"가 되고, "paprika"는 "papapripikapa"가 된다.

이때 문장에 공백이 들어가는데 공백이 들어오는 문자열을 모두 받으려면
std::getline()을 사용한다.

*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	string ans = "";

	getline(cin, s);

	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] != 'a'&&s[i] != 'e'&&s[i] != 'i'&&s[i] != 'o'&&s[i] != 'u')
		{
			ans += s[i];
		}
		else
		{
			ans += s[i];
			i+=2;
		}
	}

	cout << ans;
}