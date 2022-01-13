#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	while (true)
	{
		string str;
		string ans = "";
		getline(cin, str);
		if (str[0] == '.' && str.size() == 1)
			return 0;
		stack<char> s;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(' || str[i] == '[')
			{
				s.push(str[i]);
			}
			else if (str[i] == ')')
			{
				if (s.empty() || s.top() == '[')
				{
					ans = "no";
					break;
				}
				else if (s.top() == '(')
					s.pop();
			}
			else if (str[i] == ']')
			{
				if (s.empty() || s.top() == '(')
				{
					ans = "no";
					break;
				}
				else if (s.top() == '[')
					s.pop();
			}
		}
		if (ans != "no")
		{
			if (s.empty())
				ans = "yes";
			else
				ans = "no";
		}

		cout << ans << endl;
	}
	return 0;
}