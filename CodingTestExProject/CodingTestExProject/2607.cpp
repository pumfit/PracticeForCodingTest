/*
2607 비슷한 단어 

영문 알파벳 대문자로 이루어진 두 단어가 다음의 두 가지 조건을 만족하면 같은 구성을 갖는다고 말한다.

두 개의 단어가 같은 종류의 문자로 이루어져 있다.
같은 문자는 같은 개수 만큼 있다.
예를 들어 "DOG"와 "GOD"은 둘 다 'D', 'G', 'O' 세 종류의 문자로 이루어져 있으며 양쪽 모두 'D', 'G', 'O' 가 하나씩 있으므로 이 둘은 같은 구성을 갖는다. 하지만 "GOD"과 "GOOD"의 경우 "GOD"에는 'O'가 하나, "GOOD"에는 'O'가 두 개 있으므로 이 둘은 다른 구성을 갖는다.

두 단어가 같은 구성을 갖는 경우, 
또는 한 단어에서 한 문자를 더하거나, 빼거나, 
하나의 문자를 다른 문자로 바꾸어 나머지 한 단어와 같은 구성을 갖게 되는 
경우에 이들 두 단어를 서로 비슷한 단어라고 한다.

예를 들어 "DOG"와 "GOD"은 같은 구성을 가지므로 이 둘은 비슷한 단어이다. 또한 "GOD"에서 'O'를 하나 추가하면 "GOOD" 과 같은 구성을 갖게 되므로 이 둘 또한 비슷한 단어이다. 
하지만 "DOG"에서 하나의 문자를 더하거나, 빼거나, 바꾸어도 "DOLL"과 같은 구성이 되지는 않으므로 "DOG"과 "DOLL"은 비슷한 단어가 아니다.


입력으로 여러 개의 서로 다른 단어가 주어질 때, 첫 번째 단어와 비슷한 단어가 모두 몇 개인지 찾아 출력하는 프로그램을 작성하시오.

문제 이해와 "하나의 문자를 더하거나, 빼거나, 바꾸어도" 이부분이 이해가 어려워서 시간이 걸린 문제
하나의 문자를 더하거나-1 0,빼거나 1 0,바꾸거나 1 -1,같거나 (모두 0)인 경우로 예외처리를 하면 맞출 수 있는 문제이다.
처음에 -1과 1만 생각해서 67번 라인 반복문 안에 2크기의 배열로 나타냈는데 모두 0인 경우를 빼먹은 것을 알게되아 추가하느라
코드가 이상해졌다. num[subAlpabet[k]+1]로 바꾸면 더 코드가 줄 것 같다. 역시 문제풀이 전에 잘 설계를 해야 좋은 코드가 완성되는 것을 느꼈다.
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int T;
	vector<string> word;
	int alpabet[26] = { 0, };
	int ans = 0;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		string s;
		cin >> s;
		word.push_back(s);
	}
	for (int i = 0; i < word[0].length(); i++)
	{
		alpabet[word[0][i] - 'A']++;

	}

	for (int i = 1; i < T; i++)
	{
		int subAlpabet[26] = { 0, };
		int num[3] = { 0, };
		bool isSimilar = true;
		for (int j = 0; j < 26; j++)
		{
			subAlpabet[j] = alpabet[j];
		}

		for (int j = 0; j < word[i].length(); j++)
		{
			subAlpabet[word[i][j] - 'A']--;
		}

		for (int k = 0; k < 26; k++)
		{
			if (subAlpabet[k] == 1)
			{
				num[1]++;
			}
			else if (subAlpabet[k] == -1)
			{
				num[0]++;
			}
			else if (subAlpabet[k] == 0)
			{
				num[2]++;
			}
			else if (subAlpabet[k] != 0)
			{
				isSimilar = false;
			}
		}

		if ((num[1] == 1 && num[0] == 0) || (num[0] == 1 && num[1] == 0) || (num[1] == 1 && num[0] == 1) || num[2] == 26)
		{
			if (isSimilar == true)
			{
				ans++;
			}
		}
	}
	cout << ans;
}