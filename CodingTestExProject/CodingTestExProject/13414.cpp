/*
13414 수강신청

https://www.acmicpc.net/problem/13414

국민대학교에서는 매 학기 시작 전 종합정보시스템에서 수강신청을 한다. 매 수강신청마다 아주 많은 학생들이 몰려 서버에 많은 부하가 가기 때문에, 국민대학교에서는 수강신청 부하 관리 시스템을 도입하기로 결정하였다. 새로운 관리 시스템은 다음과 같은 방식으로 동작한다.

수강신청 버튼이 활성화 된 후, 수강신청 버튼을 조금이라도 빨리 누른 학생이 대기목록에 먼저 들어간다.
이미 대기열에 들어가 있는 상태에서 다시 수강신청 버튼을 누를 경우 대기목록의 맨 뒤로 밀려난다.
잠시 후 수강신청 버튼이 비활성화 되면, 대기목록에서 가장 앞에 있는 학생부터 자동으로 수강신청이 완료되며, 수강 가능 인원이 꽉 찰 경우 나머지 대기목록은 무시하고 수강신청을 종료한다.

맵으로 들어오는 순서에 대해 계속 업데이트 하는 방식으로 풀었다.
다만 계속 케이스에 있어서 틀렸었는데 
출력에 있어 v의 크기보다 큰 값이 출력되는 경우에 대한 예외 처리가 되있지 않아서였다.
오랫만에 map을 value로 정렬하는 방식을 사용해서 compare함수 사용해 정렬을 진행했다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool compare(pair<string, int> &a, pair<string, int> &b)
{
	return a.second >= b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	unordered_map<string, int> m;
	int N, T;
	cin >> N >> T;
	while (T--)
	{
		string num;
		cin >> num;
		m[num] = T;
	}
	vector<pair<string, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < N; i++)
	{
		if (i > v.size() - 1)
			break;
		cout << v[i].first << '\n';
	}
	return 0;
}