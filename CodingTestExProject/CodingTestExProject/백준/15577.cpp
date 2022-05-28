/*
15577 Prodjek

Little Ivica received N math grades and wants to calculate their average. He knows that the average of two numbers a and b is calculated as (a + b) / 2, but he still doesn’t know how to do it for multiple numbers. He calculates the average by writing down N grades and repeating the following operations N - 1 times:

He chooses two numbers and erases them.
He writes down the average of the two chosen numbers.
After precisely N - 1 steps, the only number written down will be the one representing the average grade to Ivica. It is your task to determine the largest average that can be obtained this way.

주어진 배열에 두개씩 선택해 평균을 구할때 어떤 경우에 최대가 되는지 파악하면 되는 문제인데
작은 값부터 평균을 계산해주면 되는 문제이다.
정렬을 통해 작은 수부터 2개씩 평균을 구하도록 설계하였다.

그리디 문제
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
