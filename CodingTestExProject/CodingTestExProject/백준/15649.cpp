/*
15649 N�� M(1)

�ڿ��� N�� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ����

�� �ٿ� �ϳ��� ������ ������ �����ϴ� ������ ����Ѵ�. �ߺ��Ǵ� ������ ���� �� ����ϸ� �ȵǸ�, 
�� ������ �������� �����ؼ� ����ؾ� �Ѵ�.
������ ���� ������ �����ϴ� ������ ����ؾ� �Ѵ�.

�ҽ��ڵ�, �˰��� �̷п� �����ؼ� �Ʒ� �����õ鿡�� ������ �޾Ҵ�.
https://st-lab.tistory.com/114,
https://cryptosalamander.tistory.com/54
*/
#include<iostream>
#include<cstring>
using namespace std;

int N, M;
int visited[9];
int arr[9];

void bf(int idx)//����
{
	if (idx == M)//���̰� M�� ��� Ž�� �ߴ�
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++)//��ü N��ŭ Ž��
	{
		if (visited[i]==0)//�湮 �ƴ� ���
		{
			visited[i] = 1;
			arr[idx] = i;
			bf(idx+1);
			visited[i] = 0;//�湮 x�� ����
		}
	}
}

int main()
{
	cin >> N >> M;
	bf(0);

}