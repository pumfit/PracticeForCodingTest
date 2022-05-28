/*
11660 ���� �� ���ϱ� 5

dp �Ⱦ� �ڵ带 ���� ������������ 1�ۿ��� �ð��ʰ��� ������� ���ߴ�.
���� ���ظ� �߸��ؼ� ���� ��û�ϴٰ� �̻��ؼ� �˻��غ��� ���� �ľ��� �߸��� ����
�˾Ҵ�..��ǥ�� ���̸� �����ϴ°� �ƴ� ���� ���簢�� ������ ���� ����ϴ� ���̾��� Ǯ�̸� �����ߴ�.
�ð� �ʰ� ��û����
*/
#include<iostream>
using namespace std;

int memo[1025][1025] = { 0, };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, T;
	cin >> N >> T;
	for (int i = 1; i < N+1; i++)
	{
		for (int j = 1; j < N+1; j++)
		{
			int n;
			cin >> n;
			memo[i][j] = memo[i][j-1]+memo[i-1][j]-memo[i-1][j-1] + n;
		}
	}
	for (int i = 0; i < T; i++)
	{
		int sx, sy, nx, ny;
		int sum = 0;
		cin >> sy >> sx >> ny >> nx;

		cout << memo[ny][nx] - memo[sy - 1][nx] - memo[ny][sx-1] + memo[sy -1][sx - 1] << endl;;
	}
}