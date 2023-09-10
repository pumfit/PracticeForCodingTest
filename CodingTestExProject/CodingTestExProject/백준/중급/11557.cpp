/*
11557 Yangjojang of The Year
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N;
		int max = 0;
		string name = "";
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			string s;
			int n;
			cin >> s >> n;
			if (n > max)
			{
				max = n;
				name = s;
			}
		}
		cout << name << endl;
	}
	return 0;
}