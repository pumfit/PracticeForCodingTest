/*
1748 수 이어 쓰기 1

N = 10000000일때
Success #stdin #stdout 0s 5636KB
68888897

맞긴했는데 이거 bf 맞나...?? 전체 탐색해서 푼 풀이는 맞아서 맞은 것 같지만 뭔가 하나하나 탐색한게 아닌 느낌이라
문제풀이가 맞는지 의문이 들었다.

그리고 찾아본 다른 풀이

	for(int i=1;i<=n;i*=10){
		result += n - i + 1;
	}
	cout<<result;

이게 진짜 bf지...라는 생각이 드는 풀이였다.
물론 내 방법이 틀린 것도 아니고 좋은 건지 확신은 없지만 여러 풀이를 생각해보는 것은 중요한 것 같다.
*/
#include <iostream>
using namespace std;

int arr[9] = { 0,9,99,999,9999,99999,999999,9999999,99999999 };

int main() {
	int N = 0;
	cin >> N;
	int tempN = N;
	int sum = 0;
	int i = 0;
	while (tempN / 10 > 0)
	{
		i++;
		tempN /= 10;
	}
	for (int k = i; k >= 0; k--)
	{
		sum += (N - arr[k])*(k + 1);
		N = arr[k];
	}
	if (i == 0)
		sum += N;
	cout << sum;
	return 0;
}
/*
N = 10000000일때
Success #stdin #stdout 1.61s 5584KB
68888897

#include <iostream>
#include <string>
using namespace std;

int main() {
	string N;
	int sum = 0;
	cin >> N;
	while(stoi(N)>0)
	{
		sum += N.size();
		N = to_string(stoi(N)-1);
	}
	cout<<sum;
	return 0;
}
*/