/*
2581 소수 

1977완전제곱수와 비슷한 형식의 문제

자연수 M과 N이 주어질 때 M이상 N이하의 자연수 중 소수인 것을 모두 골라 이들 소수의 합과 최솟값을 찾는 프로그램을 작성하시오.
입력의 첫째 줄에 M이, 둘째 줄에 N이 주어진다.
M과 N은 10,000이하의 자연수이며, M은 N보다 작거나 같다.

1을 소수로 포함하지 않기 위해 첫 for문에 1인 경우에 2로 사용되도록 하였다.
i = 2로 하는 경우 N이 큰경우 범위 차이가 많이 날 것 이라고 생각했기 때문이다.

소수 문제를 몇가지 풀어봐서 익숙해지긴 했지만
이번 문제를 풀면서 범위 설정하는데 있어 소수 판정하고 헷갈려서 범위 설정때 제곱근을 넣는 실수도 했다.
어떤 값에 대해 소수 판정시 그 어떤 값의 제곱근 까지 판별하면 된다는 것을 잊지말자 
*/
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int M, N;
	vector<int> arr;

	cin >> N >> M;

	for (int i = N>1?N:2; i <= M; i++)
	{
		bool is = true;
		for (int k = 2; k*k <= i; k++)
		{
			if (i% k == 0)
			{
				is = false;
				break;
			}
		}
		if (is)
			arr.push_back(i);
	}
	if (arr.size() == 0)
	{
		cout << -1;
	}
	else
	{
		int sum=0;
		for (int i = 0; i < arr.size(); i++)
		{
			sum += arr[i];
		}
		cout << sum<<endl;
		cout << arr[0];
	}

}