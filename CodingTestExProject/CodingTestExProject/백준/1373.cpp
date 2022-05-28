/*
1373 2진수 8진수

처음에 2진수->10진수->8진수로 바꿨더니 실패했고
2진수를 3단위로 나눠서 8진수로 바로 변환했더니 성공했다.
위 방법을 알고있었는데 바로 적용하지 못해서 아쉬웠던 문제
자리수가 커서 string,vector를 활용해야한다는 점과
reverse함수 적절히 활용해서 계산이 편하게 하는게 포인트인 문제
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	string s;
	vector<int> v;
	cin >> s;
	reverse(s.begin(), s.end());
	int i = 0;
	while (i < s.size())
	{
		int n = 1;
		int sum = 0;
		while (i < s.size() && n < 8)
		{
			sum += ((s[i] - '0') *n);
			n *= 2;
			i++;
		}
		v.push_back(sum);
	}
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i];

	return 0;
}