/*
2587 대표값

받아온 5개의 값에 대해
평균과 대표값구하기 이때 두 수는 모두 자연수이다.
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