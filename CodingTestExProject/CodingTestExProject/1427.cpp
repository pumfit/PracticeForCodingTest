/*
1427번 소트인사이드

배열로 어떻게 가져올 것 인가?
생각한 방법 : 받아오고 %10으로 나누기 -> 정렬 후 되돌리기
이전 순서바꾸기와 비슷한 방식으로 풀이

다른방법: char[]형식으로 받아서 strlen()사용하기
+) 입력이나 출력 타입이 정해져 있지 않기 때문에 문자열로 받아도 가능하다.
해당 풀이 출처 : https://aorica.tistory.com/97
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	long int n;
	vector<int> arr;
	int idx = 0;
	
	cin >> n;

	while (n!=0)
	{
		arr.push_back(n % 10);
		n = n / 10;
		idx++;
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < idx; i++)
	{
		n *= 10;
		n += arr[idx - i - 1];
	}
	cout << n;
}