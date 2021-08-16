/*
2960 에라토스테네스의 체 ★★★

N보다 작거나 같은 모든 소수를 찾는 알고리즘
에서 K번째로 지우는 수가 무엇인지 찾는 문제

210816 재도전
주어진 문제의 순서에 맞게 구성하고 나서 k번째에 대해 찾아나갔다.
while문을 두번쓰다보니 첫 반복문에 break조건을 안 넣어서 답은 나오는데 오류가 나기도했다.
다른 풀이를 살펴보니 중첩 for문으로 깔끔하게 푸는 풀이들도 있었다. 다른 풀이들도 보고 어떻게
단순하게 풀 수 있는지 살펴보아야겠다.
*/

#include <iostream>
using namespace std;

int main()
{
	int N,K;
	int idx = 0;
	bool arr[1001] = { 0, };

	cin >> N >> K;

	int p = 2;
	while (true)
	{
		int temp = p;
		while (temp <= N)
		{
			if (!arr[temp])
			{
				arr[temp] = true;//지움
				idx++;
				if (idx == K)
				{
					cout << temp;
					break;
				}
			}
			temp += p;
		}
		while (true)
		{
			p++;
			if (!arr[p])
				break;
		}
		if (idx == K)
		{
			break;
		}
	}
}