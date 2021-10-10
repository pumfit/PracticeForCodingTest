/*
14501 ���

dfs�� Ǯ�� day�� ���� ����ϴ� �Ǽ������� �ð��� ���� ������ �׽�Ʈ���̽� �� ����ߴµ�
����� 2�۴뿡�� Ʋ�� ���� �����̴�.

Ʋ���� ���Ŀ� ������ ã�ƺ��Ҵ�.
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
	for (int i = 0; i < 2; i++)//���Ⱑ ������� ������ ���� �ʴ°� ����
	{
		if (i == 0)
		{
			cout << "i�� 0 �ΰ��" << endl;
			profit += q[day].second;
			day += q[day].first;
		}
		else
		{	
			cout << "i�� 1 �ΰ��"<<endl;
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