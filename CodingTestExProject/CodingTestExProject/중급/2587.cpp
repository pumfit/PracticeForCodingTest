/*
2587 ��ǥ��

�޾ƿ� 5���� ���� ����
��հ� ��ǥ�����ϱ� �̶� �� ���� ��� �ڿ����̴�.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> a(5);
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		int n;
		cin >> n;
		a[i] = n;
		sum += n;
	}
	sort(a.begin(), a.end());
	cout << sum/5 <<endl;
	cout << a[2]<< endl;
}