/*
1037�� ���

1.���� �����ϱ�
2.���� �������� �ľ��ϱ�
���� ����
N�� �׻� 32��Ʈ ��ȣ�ִ� ������ ǥ���� �� �ִ�. -> long int
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	long int ans = 1;
	vector<int> arr;

	int a;
	cin >> a;

	for (int i = 0; i < a; i++)
	{
		int b;
		cin >> b;
		arr.push_back(b);
	}

	sort(arr.begin(), arr.end());

	ans = arr[0] * arr[a - 1];
	cout << ans;
}