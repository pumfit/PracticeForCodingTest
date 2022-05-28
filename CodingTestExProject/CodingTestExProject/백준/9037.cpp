/*
9037 The candy war

https://www.acmicpc.net/problem/9037

���ÿ� �� ����Ʈ�� �����ε� ���ÿ� �Ѱ������ʰ� �Ѱ��ָ鼭 Ȧ������ üũ�ؼ� �����ɷȴ� ����
������ �� ����... 
���ÿ� �����ֱ� ���� add �迭�� �߰��� ������ ������ �����ߴ�.

�ٸ� Ǯ�̸� ���� ��� ���� ������ �ƴ��� �Ǵ��Ҷ� �ε��� 1~N�� 0�� ���ϴ� ����� ���� ���� �� ���Ҵ�.
*/

#include <iostream>
using namespace std;
int T,N;
bool isSame;
int arr[11]={0,};
int add[11]={0,};
void CheckIsSame()
{
	for(int j=0;j<N-1;j++)
	{
		if(arr[j]==arr[j+1])
		{
			continue;
		}else
		{
			isSame = false;
			break;
		}
	}
}
int main() {
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>N;
		for(int j=0;j<N;j++)
		{
			cin>>arr[j];
		}
		int cnt = 0;
		for(int j=0;j<N;j++)
		{
			if(arr[j]%2==1)
				arr[j]++;
		}
		isSame = true;
		CheckIsSame();
		while(!isSame)
		{
			isSame = true;
			for(int j=0;j<N;j++)
			{
				arr[j]/=2;
				add[(j+1)%N] = arr[j];
			}
			for(int j=0;j<N;j++)
			{
				arr[j] += add[j];
				if(arr[j]%2==1)
					arr[j]++;
			}
		CheckSame();
		cnt++;
		}
		cout<<cnt<<'\n';
	}
	return 0;
}