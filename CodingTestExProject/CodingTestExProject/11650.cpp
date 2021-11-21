/*
11650 좌표 정렬하기

시간초과떠서 당황했지만
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 추가하고 endl 개행 '\n'으로 변경해 48ms로 통과했다.
하지만 이는 pair를 활용한 풀이라 해당 풀이외 다른 풀이가 없나 살펴보았다.
대부분  pair를 활용한 문제풀이 방식이었고 sort에 사용자 정의함수를 사용하는 방식이 있었다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int T;
vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << " " << v[i].second << "\n";
	return 0;
}