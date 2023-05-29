/*
2661 좋은수열
https://www.acmicpc.net/problem/2661

DP 문제로 1,2,3으로 이루어지는 수열을 만들어가면서 부분 수열을 가지고 있는 지 판단하면 되는 문제였다.
다만 부분 수열을 인접한 부분에 가지고 있는 지에 대한 판단을 어떻게하면 좋을 지 고민이었는 데 수열의 길이 만큼 반으로 나누었을 때 가능한 부분 수열의 크기는
1 ~ N/2이므로 이 길이로 둘로 나눈 후에 확인해주면 된다.
*/
#include <iostream>
#include <cstring>
using namespace std;

int N;
bool isCleared = false;

void GetGoodArray(string result,int depth,int prev) {
	
	if(isCleared||depth > N)
		return;
		
    // 부분 수열을 가지고 있는 경우 더이상 BT를 진행하지 않는다.
	int len = result.size();	
	for (int i = 1; i <= len / 2; i++) {
		if (result.substr(len - i, i) == result.substr(len - 2 * i, i)) 
			return;
	}

	if(depth == N)
	{
		cout<<result;
		isCleared = true;
		return;
	}
	
	for(int i = 1;i<=3;i++)
	{
		if(prev != i)
		{
			string s = result+to_string(i);
			GetGoodArray(s,depth+1,i);
		}
	}
}

int main() {
    cin >> N;
    GetGoodArray("",0,-1);
    return 0;
}