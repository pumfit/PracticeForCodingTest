/*
2863 �̰� �м�?

����� ���� 0���� 3������ 17�� ���ο� �ѹ��� ����� �־���. (�ݺ��� ���°� �� ��ư� �����ٰ� �����ؼ�)
�м��̹Ƿ� int �� �ƴ� float�� �迭�� �����Ѵ�.
�̶� ������ A,B,C,D���� float�� �����ؾ��Ѵ�. ��갪�� �м��̹Ƿ� float�� ��ȯ�Ǿ���Ѵ�.
*/
#include<iostream>
using namespace std;

int main()
{
	float A, B, C, D;
	float arr[4] = { 0, };
	int cnt=0,max = 0;
	
	cin >> A >> B >> C >> D;

	arr[0] = A / C + B / D; 	arr[1] = C / D + A / B;		arr[2] = D / B + C / A;		arr[3] = B / A + D / C;

	max = arr[0];
	for (int i = 0; i < 4; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			cnt = i;
		}
	}
	cout << cnt;
}