/*
1547번 공

"공이 사라져서 컵 밑에 없는 경우에는 -1을 출력한다." 에 대해 생각하기가 어려웠던 문제

 +처음에 temp를 이용한 swap이 필요하지 않을까? 생각했는데

 풀이들 보면 공을 움직은 것으로 풀이 방향을 잡는 것들이 많았다.
 둘다 동일한 결과가 나온다고 하는데 첫 풀이에서는 왜 풀이가 잘못되었는지 확인해봐야할듯
*/

#include<iostream>

using namespace std;

int main()
{
	int m;
	int ans = 1;
	
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a == ans || b == ans)
		{
			ans = a == ans ? b : a;
		}
	}
	cout << ans;
}