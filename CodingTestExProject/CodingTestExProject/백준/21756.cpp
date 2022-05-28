/*
21756 지우개

https://www.acmicpc.net/problem/21756

문제 이름은 지우개지만 풀이는 반대로 홀수인 경우만 모아서 풀었다. N이 100 이라서 충분히 가능하다고 판단했고
다른 풀이는 떠오르지 않아서 위와같이 풀었는데
짧은 풀이로는 수학적으로 (1 << (int) (log(n) / log(2))); 과 같이 풀 수 있다는 것이 놀라웠다
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++)
		v.push_back(i + 1);
	while (1 != v.size())
	{
		vector<int> v2;
		for (int i = 0; i < v.size(); i++)
		{
			if (i % 2 == 1)
				v2.push_back(v[i]);
		}
		v = v2;
	}
	cout << v[0];
	return 0;
}