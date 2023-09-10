/*
2711 오타맨 고창영

고창영은 맨날 오타를 낸다. 창영이가 오타를 낸 문장과 오타를 낸 위치가 주어졌을 때, 오타를 지운 문자열을 출력하는 프로그램을 작성하시오.

첫째 줄에 테스트 케이스의 개수 T(1<=T<=1,000)가 주어진다. 각 테스트 케이스는 한 줄로 구성되어 있다. 
첫 숫자는 창영이가 오타를 낸 위치이고, 두 번째 문자열은 창영이가 친 문자열이다. 문자열의 가장 첫 문자는 1번째 문자이고, 
문자열의 길이는 80을 넘지 않고, 대문자로만 이루어져 있다. 오타를 낸 위치는 문자열 길이보다 작거나 같다.
문자열을 받아오고 반복횟수만큼 반복문을 사용해주면 풀 수 있는 문제이다.

받아온 N의 인덱스만 제외해서 답에 더하는 형식으로 문제를 풀었다.

	for (int i = 0; i < T; i++)
	{
		int N;
		string s;
		string ans = "";
		cin >> N >> s;
		for (int j = 0; j < s.length(); j++)
		{
			if (N - 1 == j) {
				continue;
			}
			else {
				ans += s[j];
			}
		}

		cout << ans << endl;
	}

해당 풀이이후 erase 함수를 사용해 해당되는 인덱스 값을 제외하고 반환되는 풀이를 아래처럼 풀어보았다.
string 의 erase함수의 인자들은 index - 지울 첫번째 문자의 위치 ,count - 지울 문자의 개수, position - 지울 문자를 가리키는 반복자 ,first, last - 지울 문자들의 범위를 가리키는 반복자들.
로 이루어져 있고 해당문제에서 지울 문자는 하나이므로 반복자는 사용하지 않았다.

erase 함수 관련 출처 : https://modoocode.com/240
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
		int N;
		string s;
		string ans = "";
		cin >> N >> s;
		ans = s.erase(N - 1, 1);
		cout << ans << endl;
	}
}