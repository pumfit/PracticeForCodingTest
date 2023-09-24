/*
1431 �ø��� ��ȣ

�ټ��̴� ��Ÿ�� ���� ������ �ִ�. �׸��� ������ ��Ÿ�� ��� �ٸ� �ø��� ��ȣ�� ������ �ִ�. �ټ��̴� ��Ÿ�� ���� ã�Ƽ� ���� ����鿡�� �������ֱ� ���ؼ� ��Ÿ�� �ø��� ��ȣ ������� �����ϰ��� �Ѵ�.

��� �ø��� ��ȣ�� ���ĺ� �빮�� (A-Z)�� ���� (0-9)�� �̷���� �ִ�.

�ø����ȣ A�� �ø����ȣ B�� �տ� ���� ���� ������ ����.

A�� B�� ���̰� �ٸ���, ª�� ���� ���� �´�.
���� ���� ���̰� ���ٸ�, A�� ��� �ڸ����� �հ� B�� ��� �ڸ����� ���� ���ؼ� ���� ���� ������ ���� �����´�. (������ �͸� ���Ѵ�)
���� 1,2�� �� �������ε� ���� �� ������, ���������� ���Ѵ�. ���ڰ� ���ĺ����� ���������� �۴�.
�ø����� �־����� ��, �����ؼ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

https://www.acmicpc.net/problem/1431

sort compare �Լ� �̿��ؼ� ������ Ǯ �� �ִ� ���� ���� ���� ���ϴ� ����� isdigit�� ����Ͽ� �������� ��ȯ�ϴ� �Լ��� �����ߴ�.

�׸��� �ʹݿ� if else if�� ��ȯ�ߴµ� �׷� �ʿ���� ������ "�� ������ ���̰� ���� �ʴٸ�"
if(lena != lenb) 
	return lena < lenb;
�̷� ������ ������ �޾� �����ϴ°� ���� ����ϴ�
*/
#include <iostream>
#include <algorithm>
using namespace std;

string str[51];

int SumNumber(string& str)
{
	int n = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (isdigit(str[i]))
			n += (str[i] - '0');
	}
	return n;
}

bool compare(string& A, string& B)
{
	if (A.size() < B.size())
	{
		return true; // A�� B�� ���̰� �ٸ���, ª�� ���� ���� �´�.
	}
	else if (A.size() > B.size())
	{
		return false;
	}
	else {
		int a = SumNumber(A); int b = SumNumber(B);
		if (a < b)//A�� ��� �ڸ����� �հ� B�� ��� �ڸ����� ���� ���ؼ� ���� ���� ������ ���� �����´�. 
			return true;
		else if (a > b)
			return false;
		else
			return A < B;
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> str[i];
	sort(str, str + N, compare);
	for (int i = 0; i < N; i++)
		cout << str[i] << '\n';
	return 0;
}