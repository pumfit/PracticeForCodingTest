/*
15577 Prodjek

Little Ivica received N math grades and wants to calculate their average. He knows that the average of two numbers a and b is calculated as (a + b) / 2, but he still doesn��t know how to do it for multiple numbers. He calculates the average by writing down N grades and repeating the following operations N - 1 times:

He chooses two numbers and erases them.
He writes down the average of the two chosen numbers.
After precisely N - 1 steps, the only number written down will be the one representing the average grade to Ivica. It is your task to determine the largest average that can be obtained this way.

�־��� �迭�� �ΰ��� ������ ����� ���Ҷ� � ��쿡 �ִ밡 �Ǵ��� �ľ��ϸ� �Ǵ� �����ε�
���� ������ ����� ������ָ� �Ǵ� �����̴�.
������ ���� ���� ������ 2���� ����� ���ϵ��� �����Ͽ���.

�׸��� ����
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;

int main() {
	cin >> N;
	vector<int> v;
	int a = 0; float sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	sum = v[0];
	for (int i = 1; i < N; i++)
	{
		sum = (sum + v[i]) / 2;
	}
	printf("%f", sum);
	return 0;
}
