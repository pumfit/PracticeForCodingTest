/*
1620 나는야 포켓몬 마스터 이다솜

https://www.acmicpc.net/submit/1620/42761045

이름->번호, 번호->이름 전환을 위해 맵을 두개 사용하였고
숫자의 경우 isdigit을 사용해 숫자인지 판별했는데

맵을 두개 사용하지 않고 아래와 같이 풀 수도 있다.(INT -> STRING)이므로
unordered_map<string, int> s2i;
string i2s[100005];
또한 isdigit으로 첫자리만 숫자인지 판별하면 된다.

  for(int i = 1; i <= n; i++){
	cin >> i2s[i]; //i번째에 string을 넣음
	s2i[i2s[i]] = i;// string key에 i value를 가짐
  }
*/
#include <iostream>
#include <unordered_map>
using namespace std;

bool isNumber(string& s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (isdigit(s[i]) == false)
			return false;
	}
	return true;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	unordered_map<int, string> numMap;
	unordered_map<string, int> nameMap;
	int N, T;
	cin >> N >> T;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		numMap[i + 1] = s;
		nameMap[s] = i + 1;
	}
	while (T--)
	{
		string s;
		cin >> s;
		if (isNumber(s))
		{
			cout << numMap[stoi(s)] << '\n';
		}
		else {
			cout << nameMap[s] << '\n';
		}

	}
	return 0;
}