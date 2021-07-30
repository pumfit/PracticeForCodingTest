/*
2703 Cryptoquote
Cryptoquote는 어떤 메시지가 있을 때, 각 알파벳을 다른 알파벳으로 변환해 암호화 하는 방법으로
예를 들어, HPC PJVYMIY란 메시지가 있을 때, 이를 원래 메시지로 바꾼다면 ACM CONTEST가 된다.
문제에서는 암호문과 해독을 위한 규칙이 주어진다.

한줄 모두 입력받기 getlin() 함수를 이전 문제 풀이시 사용했었는데
이번 문제풀이시엔 이전에 받아온 T의 개행이 들어가는 문제가 있어 cin.ignore()함수를 사용하게 되었다.
getline함수와 cin.ignore()를 통해 쉽게 암호화된 문자열을 받아올 수 있었다.
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