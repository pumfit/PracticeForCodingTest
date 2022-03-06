/*
13300 Strfry 

https://www.acmicpc.net/problem/11328

*/
#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int alphabet[26] = { 0, };
		bool isPossible = true;
		string s1, s2;
		cin >> s1 >> s2;
		for (int i = 0; i < s1.size(); i++)
			alphabet[s1[i] - 'a']++;
		for (int i = 0; i < s2.size(); i++)
			alphabet[s2[i] - 'a']--;
		for (int i = 0; i < 26; i++)
		{
			if (alphabet[i] != 0)
			{
				isPossible = false;
				cout << "Impossible" << "\n";
				break;
			}
		}
		if (isPossible)
			cout << "Possible" << "\n";
	}
	return 0;
}