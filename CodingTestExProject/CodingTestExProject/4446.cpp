/*
4446 ROT13

EoF 파일 끝에 대한 처리를 이번 문제로 처음 알았다.

그런데 33퍼 이후로 틀리는 이유를 모르겠다.

*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

char vowels[6] = { 'a','i','y','e','o','u' };
char upVowels[6] = { 'A','I','Y','E','O','U' };
char con[20] = { 'b', 'k', 'x', 'z', 'n', 'h', 'd', 'c', 'w', 'g', 'p', 'v', 'j', 'q', 't', 's', 'r', 'l', 'm', 'f' };
char upCon[20] = { 'B', 'K', 'X', 'Z', 'N', 'H', 'D', 'V', 'W', 'G', 'P', 'V', 'J', 'Q', 'T', 'S', 'R', 'L', 'M', 'F' };

int main()
{
	string s;
		
	while(getline(cin, s))
	{
		bool isVowel = false;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != ' ')
			{
				for (int j = 0; j < 6; j++)
				{
					if (s[i] == vowels[j])//모음의 경우
					{
						s[i] = vowels[(j - 3>=0?j-3:j+3) % 6];
						isVowel = true;
						break;
					}
					else if (s[i] == upVowels[j])
					{
						s[i] = upVowels[(j - 3>=0?j-3:j+3) % 6];
						isVowel = true;
						break;
					}
				}
				if (!isVowel)
				{
					for (int j = 0; j < 20; j++)
					{
						if (s[i] == con[j])//자음의 경우
						{
							s[i] = con[(j - 10>=0?j-10:j+10) % 20];
							break;
						}
						else if (s[i] == upCon[j])
						{
							s[i] = upCon[(j - 10>=0?j-10:j+10) % 20];
							break;
						}
					}
				}
			}
			isVowel = false;
		}
		cout << s<<endl;
	}

}