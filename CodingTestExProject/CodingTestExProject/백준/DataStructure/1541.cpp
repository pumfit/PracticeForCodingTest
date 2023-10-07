/*
1541 �Ҿ���� ��ȣ

https://www.acmicpc.net/problem/1541

�����̴� ����� +, -, �׸��� ��ȣ�� ������ ���� �������. �׸��� ���� �����̴� ��ȣ�� ��� ������.
�׸��� ���� �����̴� ��ȣ�� ������ �ļ� �� ���� ���� �ּҷ� ������� �Ѵ�.
��ȣ�� ������ �ļ� �� ���� ���� �ּҷ� ����� ���α׷��� �ۼ��Ͻÿ�.

���ڿ�+����(��ȣ)
���� ������� -�� ���ö������� ���� �������ִٰ� ���ָ� �ȴ�.
�̰ͺ��� ���ڿ� ó���ϴµ� �� �ɸ� �� ����.
�����ڰ� ������ ��� substr�� ����� �߶� �־��� ������ ���� ��� ���� �־����.

�������� substr�Ἥ ���� isidigit�� num = num * 10 + (str[i] - '0'); ������ ����ϴ°� ���� ������. (�� �����pass)

�����ھƴ� ��� string���� ���ؼ� ó���ϴ� ������ Ǯ�� ���� stack�Ⱦ��� ���� ������ �� ���� �̷��Ե� Ǯ �� �ֱ���
https://scarlettb.tistory.com/64
*/
#include <iostream>
#include <stack>
using namespace std;

int main() {
	string s;
	cin >> s;
	stack<string> arr;
	int sIdx = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '-' || s[i] == '+')
		{
			string c = "";
			c += s[i];
			arr.push(s.substr(sIdx, i - sIdx));
			arr.push(c);
			sIdx = i + 1;
		}
	}
	arr.push(s.substr(sIdx, s.size() - sIdx));
	int ans = 0;
	int tempSum = 0;
	while (!arr.empty())
	{
		string c = arr.top();
		arr.pop();
		if (c == "-")
		{
			ans -= tempSum;
			tempSum = 0;
		}
		else if (c != "+")
		{
			tempSum += stoi(c);
		}
	}
	ans += tempSum;
	cout << ans;
	return 0;
}