/*
1408�� 24

���� ��ü�� ��մ� �����̴�.

����Ʈ ������ printf�� �����ϴ� ����� �� ��������ʾ� �������.
print("%02d" ~) ���� %: ����� ����,0: ä���� ����,2: �� �ڸ���,d; 10����(����)
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