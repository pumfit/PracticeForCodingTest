/*
5430 AC

https://www.acmicpc.net/problem/5430

3트만에 맞췄는데 틀린 이유들이 하나같이 이상해서 어이가 없던 문제
1. 마지막 ']' 처리를 잘못해서 배열이 빈경우 '['만 나옴
2. break를 continue로 씀
2번은 조건문 덕지덕지라 안보여서 그랬다고 해도 너무한 실수.. 주의하자
배열을 가져오는 건 이전처럼 istringstream을 썼는데 while문에서 getline함수를 쓴다는걸 잊었다. 여러번 쓰면서 익히자
(이 방식으로 가져오면서 문제에 주어진 n도 사용하지 않았다.)
정답율 낮아서 무서웠는데 로직 자체는 덱이라는걸 알고 푸니까 바로 풀어서 빠르게 풀 수 있었던 문제이다.
*/
#include <iostream>
#include <sstream>
#include <deque>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int n;
		string p;
		string x;
		deque<int> q;
		cin >> p >> n >> x;
		x = x.substr(1, x.size() - 2);
		istringstream ss(x);
		string s;
		while (getline(ss, s, ','))
		{
			q.push_back(stoi(s));
		}
		bool isFront = true;
		bool isError = false;
		for (int i = 0; i < p.size(); i++)
		{

			if (p[i] == 'R')
			{
				if (isFront)
				{
					isFront = false;
				}
				else {
					isFront = true;
				}
			}
			else {
				if (q.empty())
				{
					isError = true;
					cout << "error" << '\n';
					break;
				}
				else {
					if (isFront) {
						q.pop_front();
					}
					else {
						q.pop_back();
					}
				}
			}
		}
		if (!isError)
		{
			cout << '[';
			if (isFront)
			{
				for (int i = 0; i < q.size(); i++)
				{
					if (i == q.size() - 1)
						cout << q[i];
					else
						cout << q[i] << ',';
				}

			}
			else {
				for (int i = q.size() - 1; i >= 0; i--)
				{
					if (i == 0)
						cout << q[i];
					else
						cout << q[i] << ',';
				}

			}
			cout << ']' << '\n';
		}
	}

	return 0;
}