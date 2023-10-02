/*
17413 단어 뒤집기 2
https://www.acmicpc.net/source/67417773


*/
#include <iostream>
using namespace std;

int main() {
	string str;
	getline(cin, str);
	for(int i = 0; i<str.size();i++)
	{
		if(str[i]=='<')
		{
			while(str[i]!='>')
				i++;
		}else if(str[i]!=' '&&str[i]!='<')
		{
			int prev = i;
			while(i+1<str.size() && str[i+1]!=' '&&str[i+1]!='<')
				i++;
			string sub = str.substr(prev,i+1-prev);
			for(int j = prev;j<i+1;j++)
				str[j] = sub[sub.size()-(j-prev)-1];
		}
	}
	cout<<str;
	return 0;
}