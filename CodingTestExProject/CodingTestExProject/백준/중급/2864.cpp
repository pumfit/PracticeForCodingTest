/*
2864 5�� 6�� ����

�� Ǯ�� :
�ش� ������ �ּҰ��� �ִ밪�� ã���� �ǹǷ�
�ּҰ��� ��� 6�� ã�Ƽ� 5�� �ٲ��ָ� �ǰ� �ִ밪�� ��� 5�� ã�Ƽ� 6���� �ٲ��ָ� �ȴ�.

������ Ǯ�����ؼ� string�� stoi()�Լ��� ����ߴ�.
*/

#include<iostream>
#include<string>
using namespace std;

int min(string n)
{
	for (int i = 0; i < n.length(); i++)
	{
		if (n[i] == '6')
			n[i] = '5';
	}
	return 	stoi(n);
}

int max(string n)
{
	for (int i = 0; i < n.length(); i++)
	{
		if (n[i] == '5')
			n[i] = '6';
	}
	return 	stoi(n);
}

int main()
{
	string A,B;
	cin >> A >> B;
	cout << min(A) + min(B) << " " << max(A) + max(B)<<endl;
}