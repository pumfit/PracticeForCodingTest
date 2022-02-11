/*
1141 ���λ�

���λ�X �����̶� ������ � �� �ܾ, �ٸ� �ܾ��� ���ξ ���� �ʴ� �����̴�. ���� ���, {hello}, {hello, goodbye, giant, hi}, ����ִ� ������ ��� ���λ�X �����̴�. ������, {hello, hell}, {giant, gig, g}�� ���λ�X ������ �ƴϴ�.

�ܾ� N���� �̷���� ������ �־��� ��, ���λ�X ������ �κ������� �ִ� ũ�⸦ ����Ͻÿ�.
https://www.acmicpc.net/problem/1141

Ǯ�������� ������ ���� ���� �� ���� Ǯ�� ������ ���� �� ����.
���� ���λ簡 �Ǹ� �����ϸ� �Ǵ� �����̴�.
���ڿ��� vector�� �޾ƿ� ������ �� �� i��°�� i+1���� ���λ簡 �Ǵ� �� Ȯ���غ���.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<string> v;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	int ans = v.size();
	for (int i = 0; i < v.size(); i++)
	{
		int cnt = 0;
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[i][0] != v[j][0])//ù ���ڰ� �ٸ� ��� break
				break;
			else
			{
				bool isPre = true;//���λ� ���� �Ǵ�
				for (int k = 0; k < v[i].size(); k++)
				{
					if (v[i][k] != v[j][k])
					{
						isPre = false;
						break;
					}
				}
				if (isPre)
					cnt++;//���λ� ����
			}
		}
		if (cnt > 0)
			ans--;//���λ簡 �����ϴ� ��� ����
	}
	cout << ans;
	return 0;
}