/*
9946 단어 퍼즐

준하는 유치원에서 단어 퍼즐게임을 즐겨한다.
단어 퍼즐게임이란, 주어진 알파벳들을 섞어서 단어를 만드는 게임이다.

천재 준하는 알파벳을 임의로 조합하여, 사전과 매칭된 단어를 만드는 프로그램을 만들어 단어를 완성시켰다.
그러나 완성된 단어를 원장님에게 가져가려는 순간, 지나가던 강민이와 부딫혀서 단어조각을 땅에 떨어뜨리고 말았다.

준하는 어찌어찌 조각을 회수했지만, 순서는 뒤죽박죽이 되었고, 알파벳이 부족하거나 다른 알파벳이 섞였을 수도 있다.
준하가 처음에 완성한 단어와 나중에 회수한 알파벳들이 주어질 때,

준하가 알파벳을 제대로 회수했는지 안했는지 판단하는 프로그램을 만들어주자.

입력은 케이스마다 두줄로 이루어져있다.
첫째 줄은 준하가 처음 완성한 단어이고, 둘째 줄은 떨어뜨린 다음 회수한 알파벳들이다.
각 줄은 알파벳 소문자로 이루어져 있고, 길이는 1000을 넘지 않는다.
마지막에 END라는 단어가 두줄 주어지는데, 이는 케이스의 끝을 의미한다.

비슷한 유형 문제들 많이 풀어봤는데 오랫만에 푸니 또 달랐다. 소문자만 있다는 점에서 쉬웠던 문제
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2;
	int i = 0;
	while (true)
	{
		i++;
		cin >> s1 >> s2;
		int a1[26] = { 0, };
		bool isDifferent = false;
		if (!s1.compare("END"))
		{
			return 0;
		}
		if (s1.size() != s2.size())
		{
			cout << "Case " << i << ": different" << endl;
		}
		else
		{
			for (int k = 0; k < s1.size(); k++)
			{
				a1[s1[k] - 'a']++;
				a1[s2[k] - 'a']--;
			}
			for (int k = 0; k < 26; k++)
			{
				if (a1[k] != 0)
				{
					cout << "Case " << i << ": different" << endl;
					isDifferent = true;
					break;
				}
			}
			if (!isDifferent)
			{
				cout << "Case " << i << ": same" << endl;
			}
		}
	}
}