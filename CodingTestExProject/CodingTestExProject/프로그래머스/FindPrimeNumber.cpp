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

/*
조합 공부하고 나서 변경한 풀이
next_permutation사용시 꼭 정렬을 진행하도록 한다. 테케 하나 통과 못했는데 해당부분 수정하니 넘어갔다.
생각해보니 굳이 벡터써서 몇개까지 선택할건지 안하고 i값까지만 넣어주면 되는데 이전에 봤던 코드 영향으로
그냥 그렇게 쓴것 같다. 이부분은 수정하는게 좋을 것 같다.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

//소수 판별
bool isPrime(int n)
{
	if (n == 0 || n == 1)
		return false;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
//조합 만들고 소수 판별해서 카운트 올리는 방식
int solution(string numbers) {
	int N = numbers.size();
	int answer = 0;
	set<int> num;
	sort(numbers.begin(), numbers.end());
	for (int i = 1; i <= N; i++)
	{
		do {
			string s = "";
			for (int j = 0; j < N; j++)
			{
				if (j <= i - 1)
					s += numbers[j];
			}
			num.insert(stoi(s));
		} while (next_permutation(numbers.begin(), numbers.end()));
	}
	for (auto n : num)
	{
		if (isPrime(n))
			answer++;
	}
	return answer;
}