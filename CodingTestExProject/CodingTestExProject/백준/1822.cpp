
/*
1822 차집합

이분탐색 문제
조건중 출력 내용도 정렬되어야하는데 A 정렬안했다가 한번 틀림
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> B;

bool findNum(int n, int st, int ed)
{
	int mid = (st + ed) / 2;
	while (st <= ed)
	{
		if (B[mid] > n)
		{
			ed = mid - 1;
		}
		else if (B[mid] < n)
		{
			st = mid + 1;
		}
		else
		{
			return true;
		}
		mid = (st + ed) / 2;
	}
	return false;
}

int main() {
	int N, M, n;
	cin >> N >> M;
	vector<int> A;
	vector<int> C;
	while (N--)
	{
		cin >> n;
		A.push_back(n);
	}
	while (M--)
	{
		cin >> n;
		B.push_back(n);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	for (int i = 0; i < A.size(); i++)
	{
		if (findNum(A[i], 0, B.size() - 1) == false)
		{
			C.push_back(A[i]);
		}
	}
	cout << C.size() << '\n';
	for (int i = 0; i < C.size(); i++)
		cout << C[i] << " ";
	return 0;
}