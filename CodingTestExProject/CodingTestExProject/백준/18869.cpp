/*
18869 멀티 버스2
https://www.acmicpc.net/problem/18869

좌표 압축 풀이를 알고 있어야 문제 풀이 방식이 보이는 문제
각 행성 크기를 압축한 뒤 같은지 확인해보면 된다.

- 좌표 구할때 유니크 사용해서 중복 값 없애기
- 같은 우주 쌍 찾는 로직

 처음에 맵 사용해서 값이 2이상이면 정답을 1 증가시켰는데 해당 방법으로는 계속 틀렸고
 이중 for문으로 범위 줄여가면서 하면 정답으로 처리되었다.

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int N, M, n;

bool compare(string a, string b) {
	for (int k = 0; k < M; k++)
	{
		if (a[k] != b[k])
			return false;
	}
	return true;
}

int main() {
	int answer = 0;
	vector<int> v[101];
	map<string, int> m;
	vector<string> str;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> n;
			v[i].push_back(n);
		}
		vector<int> sort_v(v[i].begin(), v[i].end());
		sort(sort_v.begin(), sort_v.end());
		sort_v.erase(unique(sort_v.begin(), sort_v.end()), sort_v.end());
		string s = "";
		for (int j = 0; j < M; j++)
		{
			s += (lower_bound(sort_v.begin(), sort_v.end(), v[i][j]) - sort_v.begin()) + '0';
		}
		str.push_back(s);
	}
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			answer += compare(str[i], str[j]);
		}
	}
	cout << answer;
	return 0;
}