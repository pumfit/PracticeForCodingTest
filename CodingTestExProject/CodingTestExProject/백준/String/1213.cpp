/*
1213 펠린드롬 만들기
https://www.acmicpc.net/problem/1213

c++ algorithm의 reverse 함수는 원형을 변경한다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string str;
	int arr[26] = {0,};
	int isAdd = 0;
	cin>>str;
	
	for(int i = 0; i<str.size();i++)
		arr[str[i]-'A']++;

    int oddCount = 0;
    string front = "",mid = "";
    for (int i = 0; i < 26; i++) {
        if (arr[i] % 2 == 1)
        {
        	mid += ('A'+i);
        	oddCount++;
        	if (oddCount > 1) 
        	{
            	cout << "I'm Sorry Hansoo";
            	return 0;
        	}
        }
        
        for(int j = 0;j<arr[i]/2;j++)
			front += ('A'+i);
        
    }
	
	string s = front+mid;
	reverse(front.begin(), front.end());
	cout<<s+front;
	
	return 0;
}