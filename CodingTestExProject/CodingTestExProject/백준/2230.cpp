/*
2230 수고르기
https://www.acmicpc.net/problem/2230

이분탐색, 투 포인터 문제

처음에 이분탐색으로 풀었을때 15%에서 틀려서 뭐가 잘못된거지 싶었고
투 포인터 풀이로 풀어보면서 Out of Index 나고 답 보고 고친 후에도 똑같이 15%에서 틀렸었다.

그 후 답에서 다른 점을 찾아보니 처음 최소값 초기화 값을 0x7fffffff 로 정한게 다르다는 점을 알아냈다.
이전부터 max값 초기화할때 1e9를 썼었는데 이보다 큰 최소값이 테케에 들어가 이것 때문에 틀릴 수도 있구나 싶었다.
이분탐색 풀이도 다시 가서 1e9 -> 2e9로 고치니 통과했다.

문제 자체는 이분탐색이랑 투 포인터 모두 풀어보기 좋은 문제인 것 같다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int>v;
	int N, M;
	cin >> N >> M;
	int n = 0, answer = 0x7fffffff, en = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	for (int st = 0; st < N; st++)
	{
		while (en < N && v[en] - v[st] < M)
			en++;
		if (en == N)//en 범위가 N보다 커지는 경우에는 종료
			break;

		answer = min(answer, v[en] - v[st]);

	}
	cout << answer;

	return 0;
}

/*
이분탐색 lower_bound 사용
- 이후에 이분탐색 직접 구현으로 다시 풀기

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int>v;
	int N,M;
	cin>>N>>M;
	int n=0,answer=2e9;
	while(N--)
	{
		cin>>n;
		v.push_back(n);
	}
	sort(v.begin(),v.end());
	for(int i = 0;i<v.size();i++)
	{
		int index = lower_bound(v.begin(), v.end(), v[i] + M) - v.begin();
		int value = v[index] - v[i];
		if(value>=M)
			answer = min(answer,value);
	}
	cout<<answer;

	return 0;
}
*/