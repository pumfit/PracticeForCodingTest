/*
10808 ¾ËÆÄºª °³¼ö

https://www.acmicpc.net/problem/10808
*/
#include <iostream>
using namespace std;

int main() {
	int alphabet[26] = { 0, };
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		alphabet[s[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++)
		cout << alphabet[i] << " ";
	return 0;
}