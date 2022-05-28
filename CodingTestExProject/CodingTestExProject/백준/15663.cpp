/*
15663 N��M (9)

N���� �ڿ����� �ڿ��� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

N���� �ڿ��� �߿��� M���� �� ����

https://www.acmicpc.net/problem/15663

���� �ߺ��Ǵ� ��츦 �����ؾ��ϴµ� �̰Ÿ� ��� �ؾ��ұ� ����ϴٰ� prev�� ���� �� ������ �����ߴµ�
��� �����ؾ����� �𸣰ھ ������� ����
for���� ���� idx�� ���� arr ���� ������ ������ �����Ƿ� ���⼭ ���õ� ���� prev�� �����ϰ�
���� ���� ���ؼ� �����ϸ� �Ǵ� ���̿���.

set���� �ߺ� �Ÿ��� Ǯ��Ҵµ� �ش� ����� �����ߴ�. �Ʒ� ����
*/
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int N, M;
int num[10] = { 0, };
int arr[10] = { 0, };
int visited[10] = { 0, };
int prevNum = 0;

void bf(int idx)
{
	if (idx == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	int prev = 0;
	for (int i = 0; i < N; i++)
	{
		if (visited[i] == 0 && prev != num[i])
		{
			arr[idx] = num[i];
			prev = num[i];
			visited[i] = 1;
			bf(idx + 1);
			visited[i] = 0;
		}

	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	sort(num, num + N);
	bf(0);
	return 0;
}
/*
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int N,M;
int num[10] = {0,};
int arr[10] = {0,};
int visited[10] = {0,};
int prevNum = 0;
set<string> setNum;
void bf(int idx,int depth)
{
	if(depth==M)
	{
		string s ="";
		for(int i=0;i<M;i++)
		{
			s += to_string(arr[i]);
			s += ' ';
		}
		setNum.insert(s);
		return;
	}
	for(int i=0;i<N;i++)
	{
		if(visited[i]==0)
		{
			arr[idx] = num[i];
			visited[i] = 1;
			bf(idx+1,depth+1);
			visited[i] = 0;
		}

	}
}

int main() {
	cin>>N>>M;
	for(int i=0;i<N;i++)
		cin>>num[i];
	sort(num,num+N);
	bf(0,0);
	for(auto i:setNum)
		cout<<i<<'\n';
	return 0;
}
*/