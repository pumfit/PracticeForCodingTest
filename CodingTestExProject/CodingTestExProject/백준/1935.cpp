/*
1935 ���� ǥ���

ù° �ٿ� �ǿ������� ����(1 �� N �� 26) �� �־�����. �׸��� ��° �ٿ��� ���� ǥ����� �־�����. (���⼭ �ǿ����ڴ� A~Z�� ���빮���̸�, A���� ������� N���� ���빮�ڸ��� ���Ǹ�, ���̴� 100�� ���� �ʴ´�) �׸��� ��° �ٺ��� N+2��° �ٱ����� �� �ǿ����ڿ� �����ϴ� ���� �־�����. 3��° �ٿ��� A�� �ش��ϴ� ��, 4��° �ٿ��� B�� �ش��ϴ°� , 5��° �ٿ��� C ...�� �־�����, 
�׸��� �ǿ����ڿ� ���� �ϴ� ���� 100���� �۰ų� ���� �ڿ����̴�.
���� ǥ����� �տ������� ������� ��, ���� ����� �߰� ����� -20�ﺸ�� ũ�ų� ����, 20�ﺸ�� �۰ų� ���� �Է¸� �־�����.
https://www.acmicpc.net/problem/1935

������ �����ߴ� ������ else ������ cin���� ���ڸ� �޾��־��µ� �̷��� �����ϸ� ���� �̿��� AAB ���� ���� �� �޾ƿ´�
�������� ǥ��� �ϴϱ� �� ��Ծ ǥ��� ���� ������ ����Ʈ
https://www.notion.so/9407165018eb49a99ba6c7d859cc16d8

*C++ cout��� �Ҽ��� �ڸ��� ���ϴ� ���
cout<<fixed;
cout.precision(�ڸ���);
*/
#include <iostream>
#include <stack>
using namespace std;


int main() {
	int N;
	string s;
	cin >> N >> s;
	int number[26] = { 0, };
	stack<double> num;

	for (int i = 0; i < N; i++)
		cin >> number[i];

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '+')
		{
			double A = num.top();
			num.pop();
			double B = num.top();
			num.pop();
			num.push(B + A);
		}
		else if (s[i] == '-')
		{
			double A = num.top();
			num.pop();
			double B = num.top();
			num.pop();
			num.push(B - A);
		}
		else if (s[i] == '*')
		{
			double A = num.top();
			num.pop();
			double B = num.top();
			num.pop();
			num.push(B*A);
		}
		else if (s[i] == '/')
		{
			double A = num.top();
			num.pop();
			double B = num.top();
			num.pop();
			num.push(B / A);
		}
		else {
			num.push(number[s[i] - 'A']);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << num.top();
	return 0;
}