/*
1759 ��ȣ �����

�ٷ� ���� �ֹ��� ������ �� ���踦 �ָӴϿ� ���� ä �����ϰ� ����� �� ������ Ȳ���� ��Ȳ�� ������ ��������, 702ȣ�� ���ο� ���� �ý����� ��ġ�ϱ�� �Ͽ���. �� ���� �ý����� ���谡 �ƴ� ��ȣ�� �����ϰ� �Ǿ� �ִ� �ý����̴�.

��ȣ�� ���� �ٸ� L���� ���ĺ� �ҹ��ڵ�� �����Ǹ� �ּ� �� ���� ����(a, e, i, o, u)�� �ּ� �� ���� �������� �����Ǿ� �ִٰ� �˷��� �ִ�. ���� ���ĵ� ���ڿ��� ��ȣ�ϴ� �������� �������� �̷�� ���� ��ȣ�� �̷�� ���ĺ��� ��ȣ���� �����ϴ� ������ �迭�Ǿ��� ���̶�� �����ȴ�. ��, abc�� ���ɼ��� �ִ� ��ȣ������ bac�� �׷��� �ʴ�.

�� ���� �ý��ۿ��� �������� ��ȣ�� ������� ���� ������ ������ C������ �ִٰ� �Ѵ�. �� ���ĺ��� �Լ��� �ν�, ���� ������ �������� �濡 ħ���ϱ� ���� ��ȣ�� ������ ������ �Ѵ�. C���� ���ڵ��� ��� �־����� ��, ���ɼ� �ִ� ��ȣ���� ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.


https://www.acmicpc.net/problem/1759

�ζ� �������� ������ ������ ���� ó���� �����ϸ� �Ǵ� �����̴�.
�ζ� ���������� ũ�� ���ϰ� �����ϴ� ����� ���������ʾ� �����ɷ�����
�̹� �������� �׷� �������� ����Ǿ ���� Ǯ �� �־���.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int L, C;
char arr[15];
int num[15] = { 0, };
int visited[15] = { 0, };

void bf(int idx)
{
	if (idx == L)
	{
		bool isPass = true;
		int prev = arr[num[0]];
		int cnt = 0;
		for (int i = 0; i < L; i++)
		{
			if (arr[num[i]] == 'i' || arr[num[i]] == 'a' || arr[num[i]] == 'e' || arr[num[i]] == 'o' || arr[num[i]] == 'u')
				cnt++;
			if (prev > arr[num[i]])
			{
				isPass = false;
				break;
			}
			prev = arr[num[i]];
		}
		if (cnt == 0)
			isPass = false;
		if (L - cnt <= 1)
			isPass = false;
		if (isPass)
		{
			for (int i = 0; i < L; i++)
			{
				cout << arr[num[i]];
			}
			cout << endl;
		}
		return;
	}
	for (int i = idx; i < C; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			num[idx] = i;
			bf(idx + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++)
		cin >> arr[i];
	sort(arr, arr + C);
	bf(0);
	return 0;
}