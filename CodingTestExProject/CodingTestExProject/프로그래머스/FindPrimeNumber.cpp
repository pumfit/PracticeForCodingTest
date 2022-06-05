/*
k�������� �Ҽ� ���� ���ϱ�
2022 KAKAO BLIND RECRUITMENT

����
https://programmers.co.kr/learn/courses/30/lessons/92335

Ǯ�� �� ����
https://maybemine.tistory.com/entry/kakaoprogrammers-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%B9%B4%EC%B9%B4%EC%98%A4-%EA%B8%B0%EC%B6%9C-1%EB%8B%A8%EA%B3%84-%ED%92%80%EC%9D%B4-%EB%AA%A8%EC%9D%8C

* ���� ��ȯ, �Ҽ� �Ǻ�,���ڿ� ������
* ���� �ɷ��� �ð� �����ɷȴµ� �� ������ int�� �����÷ο� ����. ������ȯ�� ���� �ſ� Ŀ�� �� ������ �Ҽ� �Ǻ����� long �����ϱ�
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
���� �����ϰ� ���� ������ Ǯ��
next_permutation���� �� ������ �����ϵ��� �Ѵ�. ���� �ϳ� ��� ���ߴµ� �ش�κ� �����ϴ� �Ѿ��.
�����غ��� ���� ���ͽἭ ����� �����Ұ��� ���ϰ� i�������� �־��ָ� �Ǵµ� ������ �ô� �ڵ� ��������
�׳� �׷��� ���� ����. �̺κ��� �����ϴ°� ���� �� ����.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

//�Ҽ� �Ǻ�
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
//���� ����� �Ҽ� �Ǻ��ؼ� ī��Ʈ �ø��� ���
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