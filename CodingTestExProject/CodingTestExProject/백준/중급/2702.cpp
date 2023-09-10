/*
2702 ��6 ����

gcd �˰����� �����ϸ鼭 ���׿����ڷ� ���� ����� �ٲٴ� ���� �����غ��Ҵ�. 
*/

#include<iostream>
using namespace std;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

int main()
{
	int N;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int A, B;
		cin >> A >> B;
		
		int g = gcd(A, B);
		cout << A * B / g << " " << g << endl;
	}
}