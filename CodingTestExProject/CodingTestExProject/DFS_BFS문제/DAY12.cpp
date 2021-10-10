/*
14501 퇴사

dfs로 풀고 day를 먼저 계산하는 실수때문에 시간을 많이 날리고 테스트케이스 다 통과했는데
제출시 2퍼대에서 틀려 버린 문제이다.

틀리고 이후에 질문을 찾아보았다.
*/
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> q;
int m = 0,day = 0, N;

void dfs(int profit)
{
	cout<<"DAY:"<<day<<",PROFIT:"<<profit<<endl;
	if (day == N)
	{
		if (profit > m)
		{
			m = profit;
			day = 0;
		}		
		return;
	}
	for (int i = 0; i < 2; i++)//여기가 생각대로 수행이 되지 않는게 문제
	{
		if (i == 0)
		{
			cout << "i가 0 인경우" << endl;
			profit += q[day].second;
			day += q[day].first;
		}
		else
		{	
			cout << "i가 1 인경우"<<endl;
			day = day + 1;
		}
		if (day <= N)
			dfs(day);			
	}


}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int T, P;
		cin >> T >> P;
		q.push_back(make_pair(T, P));
	}
	dfs(0);
	cout << m;
	return 0;
}