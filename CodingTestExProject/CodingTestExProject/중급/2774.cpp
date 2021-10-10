/*2774 아름다운 수

아름다운 수의 정도는 그 수를 이루고 있는 10진수의 서로 다른 숫자의 개수를 의미한다.
이를 배열로 표기하여 문제풀이를 진행하였다.
*/
#include<iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N;
		int cnt = 0;
		bool arr[10] = {false,};
		cin >> N;
		while (N>0)
		{
			if(arr[N%10]==false)
				arr[N % 10] = true;
			N /= 10;
		}
		for (int j = 0; j < 10; j++)
		{
			if (arr[j] == true)
				cnt++;
		}
		cout << cnt << endl;
	}
}