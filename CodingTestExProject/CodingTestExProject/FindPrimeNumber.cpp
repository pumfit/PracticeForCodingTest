/*
k진수에서 소수 개수 구하기
2022 KAKAO BLIND RECRUITMENT

문제
https://programmers.co.kr/learn/courses/30/lessons/92335

풀이 및 공부
https://maybemine.tistory.com/entry/kakaoprogrammers-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%B9%B4%EC%B9%B4%EC%98%A4-%EA%B8%B0%EC%B6%9C-1%EB%8B%A8%EA%B3%84-%ED%92%80%EC%9D%B4-%EB%AA%A8%EC%9D%8C

* 진수 변환, 소수 판별,문자열 나누기
* 테케 걸려서 시간 오래걸렸는데 그 이유는 int형 오버플로우 였다. 진법변환시 수가 매우 커질 수 있음과 소수 판별에서 long 생각하기
*/
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

bool checkPrime(long long n)
{
	bool isPrime = true;
	if (n == 1)
		return false;
	for (long long i = 2; i*i <= n; i++)
	{
		if (n%i == 0)
		{
			isPrime = false;
			break;
		}
	}
	return isPrime;
}

int solution(int n, int k) {
	int answer = 0;
	string num = "";
	while (n > 0)
	{
		char c = n % k + '0';
		num.push_back(c);
		n = n / k;
	}
	reverse(num.begin(), num.end());

	istringstream ss(num);
	string strBuffer;
	while (getline(ss, strBuffer, '0'))
	{
		if (strBuffer == "")
			continue;
		long long i = stol(strBuffer);
		if (checkPrime(i))
			answer++;

	}
	return answer;
}