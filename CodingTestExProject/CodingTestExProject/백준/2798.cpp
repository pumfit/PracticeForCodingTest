/*
2798 ����

ī���뿡�� ���� �α� �ִ� ���� ������ ��Ģ�� ����� ����. ī���� ���� 21�� ���� �ʴ� �ѵ� ������, ī���� ���� �ִ��� ũ�� ����� �����̴�. ������ ī���븶�� �پ��� ������ �ִ�.
�ѱ� �ְ��� ���� ��� �������� ���ο� ���� ��Ģ�� ����� ���, â���̿� �����Ϸ��� �Ѵ�.

������ ������ ���迡�� �� ī�忡�� ���� ������ ���� �ִ�. �� ����, ������ N���� ī�带 ��� ���ڰ� ���̵��� �ٴڿ� ���´�. �׷� �Ŀ� ������ ���� M�� ũ�� ��ģ��.
���� �÷��̾�� ���ѵ� �ð� �ȿ� N���� ī�� �߿��� 3���� ī�带 ���� �Ѵ�. ���� ���� �����̱� ������, �÷��̾ �� ī���� ���� M�� ���� �����鼭 M�� �ִ��� ������ ������ �Ѵ�.
N���� ī�忡 ���� �ִ� ���ڰ� �־����� ��, M�� ���� �����鼭 M�� �ִ��� ����� ī�� 3���� ���� ���� ����Ͻÿ�.

bf�� 3�� for������ Ǯ�� �ִٴ� �� ���� �˰ڰ� �ش� Ǯ�̰� �±��ѵ�
�� for�� ���� ������ �����ϰ� ���� ���Ǿ��� ������ Ǯ�� ���� ��� �ϸ� ȿ�������� ������ �־��� �� ������?? ��� ������ �����.

*/
#include <iostream>
using namespace std;

int main() {
	int N, M;
	int ans = 0;
	int arr[101];

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++)
	{
		int sum = 0;
		sum += arr[i];
		for (int j = 0; j < N; j++)
		{
			if (i != j)
			{
				int ssum = sum;
				ssum += arr[j];
				for (int k = 0; k < N; k++)
				{
					if (k != i && k != j)
					{
						int sssum = ssum;
						sssum += arr[k];
						if (sssum <= M)
							ans = max(sssum, ans);
					}
				}
			}
		}

	}
	cout << ans;
	return 0;
}
/*
#include <iostream>
using namespace std;

int main() {
	int N,M;
	int ans = 0;
	int arr[101];

	cin>>N>>M;
	for(int i=0;i<N;i++)
		cin>>arr[i];

	for(int i=0;i<N-2;i++)
	{
		for(int j=i+1;j<N-1;j++)
		{
			if(i!=j)
			{
				for(int k=j+1;k<N;k++)
				{
					if(k != i&&k != j)
					{
						int sum = arr[i]+arr[j]+arr[k];
						if(sum<=M)
							ans = max(ans,sum);
					}
				}
			}
		}

	}
	cout<<ans;
	return 0;
}
*/