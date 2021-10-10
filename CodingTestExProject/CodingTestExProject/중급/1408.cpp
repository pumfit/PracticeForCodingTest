/*
1408번 24

문제 자체가 재밌는 문제이다.

프린트 형식을 printf로 지정하는 방식을 잘 사용하지않아 어려웠다.
print("%02d" ~) 뜻은 %: 명령의 시작,0: 채워질 문자,2: 총 자리수,d; 10진수(정수)
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string curTime, startTime;
	int CT = 0,ST = 0;
	int H =0, M=0, S=0;

	cin >> curTime >> startTime;

	CT = 3600 * stoi(curTime.substr(0, 2)) + 60 * stoi(curTime.substr(3, 2)) + stoi(curTime.substr(6, 2));
	ST = 3600 * stoi(startTime.substr(0, 2)) + 60 * stoi(startTime.substr(3, 2)) + stoi(startTime.substr(6, 2));
	int T = ST - CT;
	if (T > 0)
	{
		printf("%02d:%02d:%02d", T / 3600, T % 3600 / 60, T % 60);
	}
	else
	{
		T += 24 * 3600;
		printf("%02d:%02d:%02d", T / 3600, T % 3600 / 60, T % 60);
	}
}