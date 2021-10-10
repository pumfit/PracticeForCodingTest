/*
1977 완전제곱수

M과 N이 주어질 때 M이상 N이하의 자연수 중 완전제곱수인 것을 모두 골라 그 합을 구하고 그 중 최솟값을 찾는 프로그램을 작성하시오.
첫째 줄에 M이, 둘째 줄에 N이 주어진다. M과 N은 10000이하의 자연수이며 M은 N보다 같거나 작다.

풀이 이후 동적 계획법을 쓰는 풀이도 보았는데 해당 문제의 범위가 작아서 그런지
풀이 속도 차이가 큰 것 같지는 않았다.

+)개인적으로 if문안에 한줄짜리 코드가 들어가도 대괄호 넣는게 가독성이 좋고 이해하기
편하다고 생각한다. 또한 이후에 코드를 추가해야 하는 경우가 있을 수도 있으니 말이다.
*/
#include<iostream>
using namespace std;

int main()
{
	int M, N;
	int sum = 0,min=0;
	bool isFirst = true;

	cin >> M >> N;
	
	int i = 0;
	while (true)
	{
		if (M <= i * i&&i*i <= N)
		{
			if (isFirst)
			{
				min = i * i;
				isFirst = false;
			}				
			sum += i * i;
		}
		else if (i*i > N)
		{
			break;
		}
		i++;
	}
	if (isFirst)
	{
		cout << -1;
	}
	else
	{
		cout << sum<<endl;
		cout << min;
	}

}