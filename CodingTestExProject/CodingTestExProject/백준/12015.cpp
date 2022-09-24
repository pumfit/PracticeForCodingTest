/*
12015 가장 긴 증가하는 부분 수열2

https://www.acmicpc.net/problem/12015
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N, n;
	cin >> N;
	vector<int> v;
	cin >> n;
	v.push_back(n);
	for (int i = 1; i < N; i++)
	{
		cin >> n;
		if (v[v.size() - 1] < n) //step1. 입력값이 배열의 마지막값보다 큰 경우에는 배열에 추가한다.
			v.push_back(n);
		else //step2. 입력값이 배열의 마지막값보다 작은 경우는 배열내의 같거나 큰 값을 입력값으로 바꾼다.
		{
			v[lower_bound(v.begin(), v.end(), n) - v.begin()] = n;
		}
	}
	cout << v.size();
	return 0;
}